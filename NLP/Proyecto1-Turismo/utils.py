import nltk
import numpy as np
import matplotlib.pyplot as plt

from sklearn import metrics
from collections import Counter
from nltk.tokenize import TweetTokenizer
from nltk import FreqDist

def calculate_fdist(corpus_words, filter = False):
    fdist = nltk.FreqDist(corpus_words)
    aux = [(fdist[key], key) for key in fdist]
    aux.sort()
    aux.reverse()
    if filter == True: 
        fdist = aux[:1000]
    else:
        fdist = aux
    fdist = dict([(word, freq) for freq, word in fdist])
    fdist_idx = dict([(word, i) for i, word in enumerate(fdist)])
    return fdist, fdist_idx

def get_corpus(tweets, vocab):
    corpus_words = []
    for txt in tweets:
        for word in txt:
            if word in vocab:
                corpus_words.append(word)
    return corpus_words

def process_corpus(tr_txt):

    # Tokenizar y agregar <s> y </s>

    tknzr = TweetTokenizer()
    tr_txt_tknzd = [['<s>'] + tknzr.tokenize(tuit) + ['</s>'] for tuit in tr_txt]
    
    # Crear vocabulario

    vocab = set()
    for tuit in tr_txt_tknzd:
        for word in tuit:
            if word.isalpha() or word in ['<s>', '</s>']:
                vocab.add(word)

    # Crear corpus como lista y calcular fdist filtrando

    corpus_words = get_corpus(tr_txt_tknzd, vocab)
    fdist, fdist_idx = calculate_fdist(corpus_words, filter = True)
    
    # Generar vocabulario nuevo con palabras filtradas

    vocab = set(fdist.keys())
    vocab.add('<unk>')
    vocab.add('<s>')
    vocab.add('</s>')

    # Retokenizar y cambiar valores de vocab por unk

    tr_txt_tknzd = [[word if word in vocab else '<unk>' for word in tuit] for tuit in tr_txt_tknzd]

    # Generar nuevo corpus y fdist
    corpus_words = get_corpus(tr_txt_tknzd, vocab)
    fdist, fdist_idx = calculate_fdist(corpus_words)

    return tr_txt_tknzd, vocab, fdist, fdist_idx

# tr_txt_tknzd, vocab, fdist, fdist_idx = process_corpus(tr_txt)

def get_unigram_counts(vocab, tweets, fdist_idx):
    # Numpy array
    unigram_counts = np.zeros(len(vocab), dtype=np.float64)
    for tuit in tweets:
        for word in tuit:
            unigram_counts[fdist_idx[word]] += 1
    unigram_counts = unigram_counts / unigram_counts.sum()
    return unigram_counts

# unigram_counts = get_unigram_counts(vocab, tr_txt_tknzd)

def generate_sentence(unigram_counts, vocab, max_len=20):
    sentence = ['<s>']
    while len(sentence) < max_len:
        word = np.random.choice(list(vocab), p=unigram_counts)
        if word == '<s>':
            continue
        sentence.append(word)
        if word == '</s>':
            break
    return sentence

def get_bigram_counts(fdist, fdist_idx, tweets, vocab):
    bigram_counts = np.zeros(
        (len(fdist), len(fdist)),
        dtype=np.float64
    )
    for tuit in tweets:
        for i in range(len(tuit) - 1):
            if tuit[i] in vocab and tuit[i + 1] in vocab:
                bigram_counts[fdist_idx[tuit[i]], fdist_idx[tuit[i + 1]]] += 1
    for i in range(len(fdist)):
        total = np.sum(bigram_counts[i]) + len(fdist)
        bigram_counts[i] = (bigram_counts[i] + 1) / total

    return bigram_counts

# bigram_counts = get_bigram_counts(fdist, fdist_idx, tr_txt_tknzd)
# print(bigram_counts)

def generate_sentence_bigram(bigram_counts, fdist_idx, vocab, max_len=20):
    sentence = ['<s>']
    while len(sentence) < max_len:
        if sentence[-1] == '</s>':
            break
        word = np.random.choice(list(vocab), p=bigram_counts[fdist_idx[sentence[-1]]])
        sentence.append(word)
    return sentence

# print(generate_sentence_bigram(bigram_counts, fdist, fdist_idx, vocab))

# Trigrama

def get_trigram_counts(fdist, fdist_idx, tweets, vocab):
    trigram_counts = np.ones(
        (len(fdist), len(fdist), len(fdist)),
        dtype=np.float64
    )
    for tuit in tweets:
        for i in range(len(tuit) - 2):
            if tuit[i] in vocab and tuit[i + 1] in vocab and tuit[i + 2] in vocab:
                trigram_counts[fdist_idx[tuit[i]], fdist_idx[tuit[i + 1]], fdist_idx[tuit[i + 2]]] += 1
    for i in range(len(fdist)):
        for j in range(len(fdist)):
            total = np.sum(trigram_counts[i, j]) + len(fdist)
            trigram_counts[i, j] = (trigram_counts[i, j] + 1) / total

    return trigram_counts

# trigram_counts = get_trigram_counts(fdist, fdist_idx, tr_txt_tknzd)

def generate_sentence_trigram(trigram_counts, fdist, fdist_idx, vocab, max_len=20):
    sentence = ['<s>', '<s>']
    while len(sentence) < max_len:
        if sentence[-1] == '</s>':
            break
        word = np.random.choice(list(vocab), p=trigram_counts[fdist_idx[sentence[-2]], fdist_idx[sentence[-1]]])
        sentence.append(word)
    return sentence

# print(trigram_counts.shape)
# print(generate_sentence_trigram(trigram_counts, fdist, fdist_idx, vocab))

def generate_sentence_interpolation(trigram_counts, bigram_counts, unigram_counts, fdist_idx, vocab, deltas, max_len=50):
    sentence = ['<s>', '<s>']
    while len(sentence) < max_len:
        if sentence[-1] == '</s>':
            break
        word = np.random.choice(
            list(vocab), 
            p = deltas[0] * trigram_counts[fdist_idx[sentence[-2]], fdist_idx[sentence[-1]]] +
                deltas[1] * bigram_counts[fdist_idx[sentence[-1]]] +
                deltas[2] * unigram_counts
        )
        sentence.append(word)
    return sentence

# print(generate_sentence_interpolation(trigram_counts, bigram_counts, unigram_counts, fdist, fdist_idx, vocab, [0.2, 0.3, 0.5]))
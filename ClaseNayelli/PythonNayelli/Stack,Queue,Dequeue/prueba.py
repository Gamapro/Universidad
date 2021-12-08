from stack import Stack
from queue import Queue
from dequeue import Dequeue

print("STAAAACK")

p = Stack()
print(p)
for i in range(10):
    p.push(i)
print(p)
for i in range(15):
    if not p.isEmpty():
        print(p.top(),p)
    p.pop()
print(p)
    

print("QUEUEEEEEEE")

q = Queue()
print(q)
for i in range(10):
    q.push(i)
print(q)
for i in range(15):
    if not q.isEmpty():
        print(q.front(),q)
    q.pop()
print(q)


for i in range(10):
    q.push(i)
print(q)
for i in range(15):
    print(q.pop(),end = ' ') 
print(q)
for i in range(5):
    print(q.front(),end = ' ') 
print(q)


print("DEQUEUEEEEEEE")

q = Dequeue()
print(q)
for i in range(10):
    q.push_back(i)
for i in range(10):
    q.push_front(i)
for i in range(3):
    print(q.front(),end = ' ') 
print(q)
for i in range(15):
    print(q.pop_front(),end = ' ') 
print(q)


for i in range(15,19):
    q.push_front(i)
print(q)
while not q.isEmpty():
    print(q.pop_back(),end=' ')
print(q)

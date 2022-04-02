from AVL import AVL


avl = AVL()

# for i in range(10):
avl.insert(10)
avl.insert(20)
avl.insert(30)
avl.insert(40)
avl.insert(25)

print(avl)


avl.delete(30)

print(avl)

"""
# for i in range (30,-1,-5):
for i in range (0,31,5):
    avl.insert(i)
    # print(avl)
avl.insert(16)
print(avl)
avl.insert(17)
print(avl)
avl.insert(18)
print(avl)


avl.delete(5)
avl.delete(10)
avl.delete(0)
print(avl)
print(avl.contains(10))
"""

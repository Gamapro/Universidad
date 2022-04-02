from Nodes import Node
from SinglyLinkedList import SinglyLinkedList
from DoubleLinkedList import DoubleLinkedList
from CircularLinkedList import CircularLinkedList


lis = DoubleLinkedList()
for i in range(1,8,2):
    lis.push_front(i)
for i in range(0,3,2):
    lis.push_back(i)

print("\n\n\nLista Doblemente Enlazada")
print(lis)
print(lis.print())
lis.pop_front()
lis.pop_back()
lis.push_back(9)
lis.push_front(12)
print(lis.print())
print(lis.printReverse())
print(lis)

print("Antes de invertir:",lis.print())
lis.reverse()
print("Despues de invertir:",lis.print())
print("Original:",lis.printReverse())

print("Antes de remover:",lis.print())
lis.remove(12)
print("Remover 12:",lis.print())
lis.remove(1)
print("Remover 1:",lis.print())
lis.remove(10)
print("Remover 10:",lis.print())
lis.remove(9)
print("Remover 9:",lis.print())
lis.remove(15)
print("Remover 15:",lis.print())

print("Antes de invertir:",lis.print())
lis.reverse()
print("Despues de invertir:",lis.print())
print("Original:",lis.printReverse())


lis.pop_front()
lis.pop_front()
lis.pop_front()
lis.pop_back()
lis.pop_back()
lis.pop_back()
lis.pop_front()
lis.pop_front()
lis.pop_front()
print(lis)

lis.push_back(9)
lis.push_front(12)
lis.pop_back()
lis.push_back(9)
lis.push_front(13)
lis.push_back(20)
lis.push_front(15)
lis.pop_back()
lis.reverse()
# [15,13,12,9] reversed
print(lis.printReverse())
print(lis.print())
print(lis)

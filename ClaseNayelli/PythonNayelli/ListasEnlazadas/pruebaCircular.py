from Nodes import Node
from SinglyLinkedList import SinglyLinkedList
from DoubleLinkedList import DoubleLinkedList
from CircularLinkedList import CircularLinkedList


lis = CircularLinkedList()
for i in range(3):
    lis.insertHead(i)
    """print(lis.print())
    lis.printHeadTail()
    print(lis)"""
for i in range(6,9):
    lis.insertTail(i)
    


print("\n\nLista Circular")
print("INICIAL:",lis.print())
print(lis)

lis.remove(2)
print("REMOVER 2",lis.print())
lis.remove(9)
print("REMOVER 9",lis.print())
lis.remove(1)
print("REMOVER 1",lis.print())
lis.remove(6)
print("REMOVER 6",lis.print())
lis.remove(8)
print("REMOVER 8",lis.print())
print(lis)


lis.insertHead(9)
lis.insertTail(11)
lis.insertHead(13)
lis.insertHead(14)
lis.insertTail(10)
lis.remove(13)
lis.insertHead(15)
lis.remove(15)
lis.insertTail(19)

print("FINAL:",lis.print())
print(lis)

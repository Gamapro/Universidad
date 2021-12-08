from Nodes import Node
from SinglyLinkedList import SinglyLinkedList
from DoubleLinkedList import DoubleLinkedList
from CircularLinkedList import CircularLinkedList

n = Node(3)
n2 = Node(5)
n3 = Node(10)

n.next = n2
n2.next = n3

print("NODOS")
print(n)
print(n2)
print(n3)



lis = SinglyLinkedList()
for i in range(5):
    lis.insertTail(i)

print("\n\nLista Simple")
print(lis)
print(lis.print())
lis.insertHead(10)
lis.insertTail(20)
lis.remove(1)
lis.insertTail(1)
lis.insertHead(1)
print(lis.print())
lis.reverse()
print(lis.print())




from Nodes import Node

class SinglyLinkedList:
    
    def __init__(self):
        self.first = None

    def __str__(self):
        if self.first is None:
            return '[]'
        else:
            s=''
            nexto = self.first
            while nexto != None:
                s+= nexto.__str__()+'\n'
                nexto = nexto.next
            s+=''
            return s

    def print(self):
        v = []
        if self.first is not None:
            nexto = self.first
            while nexto != None:
                v.append(nexto.data)
                nexto = nexto.next
        return str(v)
    
    def insertHead(self,data):
        n = Node(data)
        n.next = self.first
        self.first = n

    def insertTail(self, data):
        n = Node(data)
        if self.first == None:
            self.first = n
        else:
            nexto = self.first
            while nexto.next != None:
                nexto = nexto.next
            nexto.next = n

    def remove(self,data):
        if self.first == None:
            remove
        if self.first.data == data:
            self.first = self.first.next
        else:
            aux = self.first
            while aux.next != None:
                if aux.next.data == data:
                    aux.next = aux.next.next
                    return
                aux = aux.next
            return

    def reverse(self):
        if self.first == None:
            return
        root = Node(self.first.data)
        aux = self.first.next
        while aux != None:
            n = Node(aux.data)
            n.next = root
            root = n
            aux = aux.next
        self.first = root
        return self

from Nodes import DoubleNode

class DoubleLinkedList:
    
    def __init__(self):
        self.first = None
        self.last = None

    def __str__(self):
        if self.first is None:
            return '[]'
        else:
            s=''
            nexto = self.first
            while nexto != None:
                s+= nexto.__str__()+"\n"
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

    def push_front(self, data):
        n = DoubleNode(data)
        if self.first == None:
            self.first = n
            self.last = n
        else:
            aux = self.first
            aux.prev = n
            n.next = aux
            self.first = n

    def push_back(self, data):
        n = DoubleNode(data)
        if self.last == None:
            self.first = n
            self.last = n
        else:
            aux = self.last
            aux.next = n
            n.prev = aux
            self.last = n

    def pop_front(self):
        if self.first == None:
            return
        self.first = self.first.next
        if self.first != None:
            self.first.prev = None

    def pop_back(self):
        if self.last == None:
            return
        self.last = self.last.prev
        if self.last != None:
            self.last.next = None

    def printReverse(self):
        v = []
        if self.last is not None:
            nexto = self.last
            while nexto != None:
                v.append(nexto.data)
                nexto = nexto.prev
        return str(v)

    def remove(self,data):
        if self.first == None:
            return
        if self.first.data == data:
            self.first = self.first.next
            self.first.prev = None
        elif self.last.data == data:
            self.last = self.last.prev
            self.last.next = None
        else:
            aux = self.first
            while aux.next != None:
                if aux.next.data == data:
                    aux.next = aux.next.next
                    aux.next.prev = aux
                    return
                aux = aux.next
            return

    def reverse(self):
        if self.first == None:
            return
        root = DoubleNode(self.first.data)
        aux = self.first.next
        while aux != None:
            n = DoubleNode(aux.data)
            n.next = root
            root.prev = n
            root = n
            aux = aux.next
        
        self.first = root
        aux = self.first.next
        while aux.next != None:
            aux = aux.next
        self.last = aux
        return


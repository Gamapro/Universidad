from Nodes import Node

class CircularLinkedList:

    def __init__(self):
        self.first = None

    def __str__(self):
        if self.first is None:
            return ''
        else:
            nexto = self.first
            s = nexto.__str__()+'\n'
            while nexto.next != self.first:
                s+= nexto.next.__str__()+'\n'
                nexto = nexto.next
            s+=''
            return s

    def print(self):
        v = []
        if self.first is not None:
            nexto = self.first
            v.append(nexto.data)
            while nexto.next != self.first:
                v.append(nexto.next.data)
                nexto = nexto.next
        return str(v)

    def insertHead(self,data):
        n = Node(data) 
        if self.first == None:
            n.next = n
            self.first = n
    
        nexto = self.first
        while nexto.next != self.first:
            nexto = nexto.next

        n.next = self.first
        self.first = n
        nexto.next = self.first

    def printHeadTail(self): 
        if self.first == None:
            return
        nexto = self.first
        print("Head:",nexto.data)
        while nexto.next != self.first:
            nexto = nexto.next
        print("Tail:",nexto.data)

    def insertTail(self, data):
        n = Node(data) 
        if self.first == None:
            n.next = n
            self.first = n
    
        nexto = self.first
        while nexto.next != self.first:
            nexto = nexto.next

        nexto.next = n
        n.next = self.first

    def remove(self,data):
        if self.first == None:
            return
        if self.first.data == data:
            if self.first.next == self.first:
                self.first = None
                return
            
            nexto = self.first
            while nexto.next != self.first:
                nexto = nexto.next

            self.first = self.first.next
            nexto.next = self.first

        else:
            nexto = self.first
            while nexto.next != self.first:
                if nexto.next.data == data:
                    nexto.next = nexto.next.next
                nexto = nexto.next




class Node:

    def __init__(self):
        self.next = None
        self.prev = None
        self.data = 0

    def __init__(self,data):
        self.next = None
        self.prev = None
        self.data = data

    def __str__(self):
        return "Data: "+str(data)


class Dequeue:

    def __init__(self):
        self.first = None
        self.last = None

    def __str__(self):
        s = "Dequeue: ["
        n = self.first
        while n != None:
            s+=str(n.data)+","
            n = n.next
        s+="]"
        return s;
    
    def push_front(self, data):
        n = Node(data)
        if self.first == None:
            self.first = self.last = n
        self.first.prev = n
        n.next = self.first
        self.first = n
        return

    def push_back(self, data):
        n = Node(data)
        if self.last == None:
            self.first = self.last = n
        self.last.next = n
        n.prev = self.last
        self.last = n
        return

    def pop_front(self):
        if self.first == None:
            return None
        aux = self.first
        if self.first == self.last:
            self.first = self.last = None 
        else:
            self.first = self.first.next
            self.first.prev = None
        cosa = aux.data
        del aux
        return cosa

    def pop_back(self):
        if self.last == None:
            return None
        aux = self.last
        if self.first == self.last:
            self.first = self.last = None 
        else:
            self.last = self.last.prev
            self.last.next = None
        cosa = aux.data
        del aux
        return cosa

    def isEmpty(self):
        return True if self.first == None else False

    def front(self):
        return None if self.first == None else self.first.data
    
    def back(self):
        return None if self.last == None else self.last.data

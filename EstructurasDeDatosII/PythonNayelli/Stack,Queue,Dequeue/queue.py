
class Node:

    def __init__(self):
        self.next = None
        self.data = 0

    def __init__(self,data):
        self.next = None
        self.data = data

    def __str__(self):
        return "Data: "+str(data)


class Queue:

    def __init__(self):
        self.first = None
        self.last = None

    def __str__(self):
        s = "Queue: ["
        n = self.first
        while n != None:
            s+=str(n.data)+","
            n = n.next
        s+="]"
        return s;

    def pop(self):
        if  self.first == None:
            return None
        aux = self.first 
        self.first = self.first.next
        cosa = aux.data
        del aux
        return cosa

    def push(self,data):
        n = Node(data)
        if self.last == None:
            self.first = self.last = n
            return
        self.last.next = n
        self.last = n

    def isEmpty(self):
        return True if self.first == None else False

    def front(self):
        return None if self.first == None else self.first.data
    


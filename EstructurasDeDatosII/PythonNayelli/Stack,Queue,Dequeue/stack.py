
class Node:

    def __init__(self):
        self.next = None
        self.data = 0

    def __init__(self,data):
        self.next = None
        self.data = data

    def __str__(self):
        return "Data: "+str(data)


class Stack:

    def __init__(self):
        self.first = None

    def __str__(self):
        s = "Stack: ["
        n = self.first
        while n != None:
            s+=str(n.data)+","
            n = n.next
        s+="]"
        return s;

    def pop(self):
        if self.first == None:
            return False
        aux = self.first 
        self.first = self.first.next
        cosa = aux.data
        del aux
        return cosa

    def push(self,data):
        n = Node(data)
        n.next = self.first
        self.first = n

    def isEmpty(self):
        return True if self.first == None else False

    def top(self):
        return None if self.first == None else self.first.data
    


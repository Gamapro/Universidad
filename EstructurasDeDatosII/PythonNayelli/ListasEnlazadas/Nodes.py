class Node:

    def __init__(self,data=0):
        self.next = None
        self.data = data

    def __str__(self):
        s = "Data: "+str(self.data)
        s += ", Direccion: &"+str(hex(id(self))) # Id - direccion, Hex - hexadecimal
        s += ", Next: &"+str(hex(id(self.next))) # Id - direccion, Hex - hexadecimal
        return s


class DoubleNode:

    def __init__(self,data=0):
        self.next = None
        self.prev = None
        self.data = data

    def __str__(self):
        s = "Data: "+str(self.data)
        s += ", Direccion: &"+str(hex(id(self))) # Id - direccion, Hex - hexadecimal
        s += ", Next: &"+str(hex(id(self.next))) # Id - direccion, Hex - hexadecimal
        s += ", Prev: &"+str(hex(id(self.prev))) # Id - direccion, Hex - hexadecimal
        return s



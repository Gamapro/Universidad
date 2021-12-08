




def insertNodo(self,data):
    n = Node(data)
    if self.first == None:
        self.first = n

    aux = self.first
    if n.data < aux.data:
        n.next = aux
        n.prev = None
        n.next.prev = n
        self.first = n
        return

    while aux.next != None and aux.next.data <= n.data:
        aux = aux.next
    
    n.next = aux.next
    aux.next = n
    n.prev = aux
    n.next.prev = n


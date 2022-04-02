
class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None
        self.parent = None
        self.balance = 0
        self.height = 1

    def __str__(self):
        return "Data:"+str(self.data)+" h:"+str(self.height)+" b:"+str(self.balance)#+" P:"+str(self.parent)

    def insert(self, node, root):
        if node.data <= self.data:
            if self.left == None:
                node.parent = self
                self.left = node
            else:
                self.left.insert(node, root)
        else:
            if self.right == None:
                node.parent = self
                self.right = node
            else:
                self.right.insert(node, root)

        ## Balances
        return self.updateBalance(root)
        # return root


    def rotateRight(self, node, root):
    # Determinar nodo a y b, parent y subarbol s2
        parent = node.parent
        a = node
        b = a.left
        s2 = b.right
    # Asignar subarbol s2 como hijo de a
        a.left = s2
        if s2 != None: s2.parent = a
    # Asignar a como hijo de b
        b.right = a
        a.parent = b
    # Reseteo padre de b
        b.parent = parent

    # Root del arbol lol
        if parent == None:
            root = a.updateBalance(root)
            root = b.updateBalance(root)
            return b # La nueva raiz
    # No-Root
        elif parent.left == a: parent.left = b
        elif parent.right == a: parent.right = b
    # Regreso la raiz original
        root = a.updateBalance(root)
        root = b.updateBalance(root)
        return root # Raiz original
 

    def rotateLeft(self, node, root):
    # Determinar nodo a y b, parent y subarbol s2
        parent = node.parent
        a = node
        b = a.right
        s2 = b.left
    # Asignar subarbol s2 como hijo de a
        a.right = s2
        if s2 != None: s2.parent = a
    # Asignar a como hijo de b
        b.left = a
        a.parent = b
    # Reseteo padre de b
        b.parent = parent

    # Root del arbol lol
        if parent == None:
            root = a.updateBalance(root)
            root = b.updateBalance(root)
            return b # La nueva raiz
    # No-Root
        elif parent.left == a: parent.left = b
        elif parent.right == a: parent.right = b
    # Regreso la raiz original
        root = a.updateBalance(root)
        root = b.updateBalance(root)
        return root # Raiz original


## Regresa la raiz, en caso de que esta cambie
    def updateBalance(self, root):
        hl = 0 if self.left == None else self.left.height
        hr = 0 if self.right == None else self.right.height
        self.height = max(hl, hr) + 1
        self.balance = hl - hr

        print("Balance ",self)

        if self.balance <= -2 and self.right.balance <=0:
            root = self.rotateLeft(self, root)

        elif self.balance <= -2 and self.right.balance == 1:
            root = self.rotateRight(self.right, root)
            root = self.rotateLeft(self, root)

        if self.balance >= 2 and self.left.balance == -1:
            root = self.rotateLeft(self.left, root)
            root = self.rotateRight(self, root)

        elif self.balance >= 2 and self.left.balance >= 0:
            root = self.rotateRight(self, root)
        
        return root



    def nodoChiquito(self,root):
        while root.right != None:
            root = root.right
        return root


    def delete(self, data, root):
        if root == None:
            return root
        if data < root.data:
            root.left = self.delete(data, root.left)
        elif data > root.data:
            root.right = self.delete(data, root.right)
    # Data es igual, eliminar este nodo
        else: 

        # Sin hijo derecho
            if root.left is None: 
                aux = root.right # Tomo el hijo que tengo 
                del root         # Me elimino
                return aux 
        # Tengo al menos el hijo izquierdo
            elif root.right is None: 
                aux = root.left 
                del root         # Me elimino
                return aux 
        # Tengo dos hijos
            aux = self.nodoChiquito(root.left) # Menor hasta la derecha 
            root.data = aux.data               # 
            root.left = self.delete(aux.data, root.left) # Elimino recursivamente

    # Regreso la nueva raiz, balanceada
        return self.updateBalance(root)
        # return root
        




class AVL:
    
    def __init__(self):
        self.root = None

    def insert(self, data):
        nodo = Node(data)
        if self.root == None:
            self.root = nodo
        else:
            self.root = self.root.insert(nodo,self.root)
        return

    def delete(self, data):
        if self.root == None:
            return
        else:
            self.root = self.root.delete(data,self.root)
        return

    def mostrarArbol(self,root,cont=0):
        if root == None:
            return
        self.mostrarArbol(root.right,cont+1)
        s=""
        for i in range(cont):
            s+=" -"
        print(s+str(root.data))
        self.mostrarArbol(root.left,cont+1)

    def contains(self, data):
        aux = self.root
        while(aux != None):
            if aux.data == data:
                return True
            elif data <= aux.data:  # Izq
                aux = aux.left
            else:
                aux = aux.right
        return False

    def DFS(self):
        st = "["
        s = list()
        s.append(self.root)
        while s != []:
            n = s.pop()
            if n == None: continue
            if n != self.root: st+=", "
            st+=str(n.data)
            if n.right != None: s.append(n.right)
            if n.left != None: s.append(n.left)
        st+="]"
        return st

    def BFS(self):
        st = "["
        q = list()
        q.append(self.root)
        while q != []:
            n = q[0]
            q = q[1:]
            if n == None: continue
            if n != self.root: st+=", "
            st+=str(n.data)
            if n.left != None: q.append(n.left)
            if n.right != None: q.append(n.right)
        st+="]"
        return st

    def preorder(self,root):
        if root != None:
            v = []
            v.append(root.data)
            x = self.preorder(root.left)
            if x != None:
                v+=x
            y = self.preorder(root.right)
            if y != None:
                v+=y

            return v
        return
        
    def inorder(self,root):
        if root != None:
            v = []
            x = self.inorder(root.left)
            if x != None:
                v+=x
            v.append(root.data)
            y = self.inorder(root.right)
            if y != None:
                v+=y

            return v
        return

    def postorder(self,root):
        if root != None:
            v = []
            x = self.postorder(root.left)
            if x != None:
                v+=x
            y = self.postorder(root.right)
            if y != None:
                v+=y
            v.append(root.data)

            return v
        return
    
    def printNode(self,root,space=""):
        if root == None: return ""
        s = space+str(root.data)+"\n"
        space+=" "
        s+=self.printNode(root.left,space)
        s+=self.printNode(root.right,space)
        return s

    def __str__(self):
        s = "Preorder - "+str(self.preorder(self.root)) +"\n"
        s+= "Inorder - "+str(self.inorder(self.root)) +"\n"
        s+= "Postorder - "+str(self.postorder(self.root)) +"\n"
        s+= "DFS - "+str(self.DFS()) +"\n"
        s+= "BFS - "+str(self.BFS()) +"\n"
        self.mostrarArbol(self.root)
        ##return self.printNode(self.root)
        return s


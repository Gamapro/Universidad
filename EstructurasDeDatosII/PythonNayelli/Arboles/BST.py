
class Node:

    def __init__(self,data=0):
        self.left = None
        self.right = None
        self.data = data

    def __str__(self):
        return str(self.data)


class BST:
    
    def __init__(self):
        self.root = None

    def insert(self, data):
        n = Node(data)
        aux = self.root
        if self.root == None:
            self.root = n
            return
        while(True):
            if data <= aux.data:  # Izquierda
                if aux.left == None:
                    aux.left = n
                    return
                else:
                    aux = aux.left
            else:                 # Derecha
                if aux.right == None:
                    aux.right = n
                    return
                else:
                    aux = aux.right

    def nodoChiquito(self,root):
        while root.right != None:
            root = root.right
        return root

    def delete(self, data, esteSi = None):
        if self.root == None:
            return
        ant = None
        aux = self.root

        while esteSi != None and aux != esteSi and aux.data == data:
            ant = aux
            if data <= aux.data:
                aux = aux.left
            else:
                aux = aux.right

        while aux != None and aux.data != data:
            ant = aux
            if data <= aux.data:
                aux = aux.left
            else:
                aux = aux.right
            
            while esteSi != None and aux != esteSi and aux.data == data:
                ant = aux
                if data <= aux.data:
                    aux = aux.left
                else:
                    aux = aux.right

        # NO ESTA - REGRESO
        if aux == None:
            return

        # CASO 1 : HOJA
        if aux.left == None and aux.right == None and aux.data == data:
            # Si mi root es mi hoja, un solo elemento 
            if aux == self.root:
                self.root = None
            else:  # Es algun otro nodo, checo con el anterior
                if ant.left == aux:
                    ant.left = None
                else:
                    ant.right = None
            del aux

        # Caso 3 : DOS HIJOS
        elif aux.right != None and aux.left != None:
            # Saco el nodo mas pequeño que es mas grande que el que tengo
            nodoCambio = self.nodoChiquito(aux.left)
            # Y lo elimino, pero guardo el valor antes
            valNodo = nodoCambio.data
            # Recursivamente uso la misma funcion delete 
            self.delete(valNodo, nodoCambio)
            # Y cambio el valor por elvalor del nodo eliminado
            aux.data = valNodo
            
        # Caso 2 : 1 hijo
        else:
            # Es parecido al caso de arriba :p
            hijo = 0
            if aux.left == None: # hay hijo derecho
                hijo = aux.right
            else:    # Hay hijo izquierdo
                hijo = aux.left

            # Si mi valor es root
            if aux == self.root:
                self.root = hijo
            else:
                if aux == ant.left: # Si originalmente estaba a la izquierda
                    ant.left = hijo
                else:  # Era el derecho
                    ant.right = hijo
            del aux

        return

    def DFS(self):
        st = "["
        s = list()
        s.append(self.root)
        while s != []:
            n = s.pop()
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
            if n != self.root: st+=", "
            st+=str(n.data)
            if n.left != None: q.append(n.left)
            if n.right != None: q.append(n.right)
        st+="]"
        return st

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

    def mostrarArbol(self,root,cont=0):
        if root == None:
            return
        self.mostrarArbol(root.right,cont+1)
        s=""
        for i in range(cont):
            s+=" -"
        print(s+str(root.data))
        self.mostrarArbol(root.left,cont+1)

    def __str__(self):
        s = "Preorder - "+str(self.preorder(self.root)) +"\n"
        s+= "Inorder - "+str(self.inorder(self.root)) +"\n"
        s+= "Postorder - "+str(self.postorder(self.root)) +"\n"
        s+= "DFS - "+str(self.DFS()) +"\n"
        s+= "BFS - "+str(self.BFS()) +"\n"
        self.mostrarArbol(self.root)
        ##return self.printNode(self.root)
        return s




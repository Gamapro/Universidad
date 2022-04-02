from BST import BST 

bst = BST()


bst.insert(5)
bst.insert(6)
bst.insert(5)
print(bst)

bst.delete(5)

print(bst)
print(bst.mostrarArbol(bst.root,0))




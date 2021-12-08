print("Alternar 2 listas")

l1 = list(input("Ingrese la primera lista: ").split(' '))
l2 = list(input("Ingrese la segunda lista: ").split(' '))

print("Lista 1:",l1)
print("Lista 2:",l2)

print("Lista alternada")
l = []
for a,b in zip(l1,l2):
	l.extend([a,b])

print(l)




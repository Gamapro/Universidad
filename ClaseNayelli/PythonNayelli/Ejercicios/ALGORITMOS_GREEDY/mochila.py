def swap(x,y):
    x ^= y
    y ^= x
    x ^= y
    return x,y

capacidad = 6
pesos = [3,1, 2, 2, 2, 1]
vals  = [2,10, 5, 6, 20, 1]
disponible = capacidad
gananciaMax = 0

print("La idea de mi algoritmo es:"," 1.- Ordenar los valores de ganancia de mayor a menor.",sep='\n')
print(" 2.- Recorrer los valores y preguntar:")
print("    - Si aun hay espacio disponible, tomar ese valor.")
print("    - Si no, checar los valores que faltan para tener la maxima ganancia.\n")

print("Capacidad Mochila:",capacidad)
n = len(pesos)
print("Pesos:",end = '')
for i in range(n):
    print(pesos[i],end=' ')
print()
print("Valores:",end = '')
for i in range(n):
    print(vals[i],end=' ')
print()

#  SORT
for i in range(1,n):
    for j in range(i,0,-1):
        if vals[j] > vals[j-1]:
            pesos[j-1], pesos[j] = swap(pesos[j-1],pesos[j]);
            vals[j-1], vals[j] = swap(vals[j-1],vals[j]);

print("VALORES ORDENADOS POR IMPORTANCIA")
print("Pesos:",end = '')
for i in range(n):
    print(pesos[i],end=' ')
print()
print("Valores:",end = '')
for i in range(n):
    print(vals[i],end=' ')
print('\n')

for i in range(n):
    print("VALOR CHECADO:",str(vals[i]),", PESO:",str(pesos[i]),", CAPACIDAD DISPONIBLE:",str(disponible))
    if disponible >= pesos[i]:
        gananciaMax+=vals[i]
        disponible-=pesos[i]
        print("Valor tomado")
    else:
        print("Valor omitido")
print()

print("La ganancia maxima fue:",str(gananciaMax))


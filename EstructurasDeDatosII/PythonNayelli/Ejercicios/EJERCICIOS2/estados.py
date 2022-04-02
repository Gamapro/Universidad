tupla =(( 'Aguascalientes','mujer'), ('Zacatecas','hombre'), ('Guanajuato','mujer'), ('Zacatecas','mujer'), ('Durango','hombre'), ('Aguascalientes','hombre'), ('Zacatecas','hombre'), ('Jalisco','hombre'), ('Zacatecas','hombre'),('Zacatecas','mujer'))

dic = dict()
seto = set()

for estado,genero in tupla:
    seto.add(estado)

print("Los estados son:")
for estado in seto:
    print(" * "+estado)
    dic[estado] = {'hombre':0,'mujer':0}

for estado,genero in tupla:
    dic[estado][genero]+=1;

print("Los generos por estado son: ")
for estado in seto:
    print()
    print(" *-- "+estado)
    print(" * ")
    print(" *-- Hombres: "+str(dic[estado]['hombre']))
    print(" * ")
    print(" *-- Mujeres: "+str(dic[estado]['mujer']))

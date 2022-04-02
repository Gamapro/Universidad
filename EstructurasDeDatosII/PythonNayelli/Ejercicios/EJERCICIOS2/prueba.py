from Figura import Figura
from Rectangulo import Rectangulo
from Cuadrado import Cuadrado

f = Figura()
f2 = Figura('Figura 2','Rojo')

print(f)
print(f2)

r1 = Rectangulo('Rect 1','Morao',3,3)
r2 = Rectangulo('Rect 2',base=-2,altura=3)
r3 = Rectangulo('Rect 3','Morao',5.4,3.8)

print(r1)
print(r2)
print(r3)

print("Rect 3 Area: ",str(r3.calcular_area()))
print("Rect 3 Perimetro: ",str(r3.calcular_perimetro()))

cuad = Cuadrado("cuadri","rojo",3)

print(cuad)
print("Cuad Area: ",str(cuad.calcular_area()))
print("cuad Perimetro: ",str(cuad.calcular_perimetro()))

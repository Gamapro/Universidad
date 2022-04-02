
from Persona import Persona
from Empleado import Empleado

p = Persona(10,apellido='Arcos')
p.edad = "ola"
p.edad = 23
p.edad = 'adios'
p.nombre = 'David'

empleado = Empleado(edad=20,nombre="Juan",apellido='Perez',salario=5)

print(p)
print(empleado)


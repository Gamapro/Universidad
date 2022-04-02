
from Persona import Persona

class Empleado(Persona):   ## HERENCIA

    def __init__(self, nombre='', apellido='', edad='', salario=''):
        Persona.__init__(self,nombre=nombre,edad=edad,apellido=apellido)
        self.__salario = salario

    def __str__(self):
        return Persona.__str__(self) + ", Salario: "+str(self.__salario)

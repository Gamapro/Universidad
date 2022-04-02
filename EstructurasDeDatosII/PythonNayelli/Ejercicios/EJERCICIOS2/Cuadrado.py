
from Figura import Figura

class Cuadrado(Figura):

    def __init__(self,nombre='',color='',lado=1):
        Figura.__init__(self,nombre,color)
        
        if type(lado) in [int, float]:
            if lado >= 0:
                self.__lado = abs(lado)
            else:
                print('El lado no puede ser negativa.')
                self.__lado = 1
        else:
            print('El lado debe de ser un numero real.')
            self.__lado = lado

    def __str__(self):
        s = Figura.__str__(self) + "\nLado: " + str(self.__lado)
        return s

    @property
    def lado(self):
        return self.__lado
    @lado.setter
    def lado(self,lado):
        if type(lado) in [int, float]:
            if lado >= 0:
                self.__lado = abs(lado)
            else:
                print('El lado no puede ser negativa.')
        else:
            print('El lado debe de ser un numero real.')

    def calcular_perimetro(self):
        return 4 * (self.__lado)

    def calcular_area(self):
        return self.__lado * self.__lado


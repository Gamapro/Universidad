
from Figura import Figura

class Rectangulo(Figura):

    def __init__(self,nombre='',color='',base=1,altura=1):
        Figura.__init__(self,nombre,color)
        
        if type(base) in [int, float]:
            if base >= 0:
                self.__base = abs(base)
            else:
                print('La base no puede ser negativa.')
                self.__base = 1
        else:
            print('La base debe de ser un numero real.')
            self.__base = base

        if type(altura) in [int, float]:
            if altura >= 0:
                self.__altura = abs(altura)
            else:
                print('La altura no puede ser negativa.')
                self.__altura = 1
        else:
            print('La altura debe de ser un numero real.')
            sef.__altura = 1

    def __str__(self):
        s = Figura.__str__(self) + "\nBase: " + str(self.__base) + ", Altura: " + str(self.__altura)
        return s

    @property
    def base(self):
        return self.__base
    @base.setter
    def base(self,base):
        if type(base) in [int, float]:
            if base >= 0:
                self.__base = abs(base)
            else:
                print('La base no puede ser negativa.')
        else:
            print('La base debe de ser un numero real.')

    @property
    def altura(self):
        return self.__altura
    @altura.setter
    def altura(self,altura):
        if type(altura) in [int, float]:
            if altura >= 0:
                self.__altura = abs(altura)
            else:
                print('La altura no puede ser negativa.')
        else:
            print('La altura debe de ser un numero real.')

    def calcular_perimetro(self):
        return 2 * (self.__base + self.__altura)

    def calcular_area(self):
        return self.__base * self.__altura


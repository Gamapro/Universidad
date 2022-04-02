
class Figura:

    def __init__(self,nombre='',color=''):
        self.__nombre = nombre
        self.__color = color

    def __str__(self):
        s = "Nombre: " + self.__nombre + ", Color: " + self.__color
        return s

    @property
    def nombre(self):        # Getter
        return self.__nombre
    @nombre.setter
    def nombre(self,nombre):   # Setter
        if isinstance(nombre,str):
            self.__nombre = nombre
        else:
            print("El nombre debe ser una cadena.")

    @property
    def color(self):        # Getter
        return self.__color
    @color.setter
    def color(self,color):   # Setter
        if isinstance(color,str):
            self.__color = color
        else:
            print("El color debe ser una cadena.")

    def calcular_perimetro(self):
        return ''

    def calular_area(self):
        return ''

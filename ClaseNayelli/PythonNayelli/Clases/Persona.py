class Persona:

    def __init__(self,edad=0,nombre='',apellido=''):  # Constructor
        self.__edad = edad  # Variable privada __           
        self.__nombre = nombre # Variable publica 
        self.apellido = apellido

    def __str__(self):  # ToString
        s = "Edad: "+str(self.__edad)
        s += ", Nombre: "+self.__nombre
        s += ", Apellido: "+self.apellido
        return s

    @property
    def edad(self):       # Getter
        return self.__edad
    @edad.setter
    def edad(self,valor): # Setter
        if isinstance(valor,int):
            self.__edad = valor
        else:
            print("La edad debe ser un valor entero")

    @property
    def nombre(self):       # Getter
        return self.__edad
    @nombre.setter
    def nombre(self,valor): # Setter
        if isinstance(valor,str):
            self.__nombre = valor
        else:
            print("El nombre debe ser una cadena")


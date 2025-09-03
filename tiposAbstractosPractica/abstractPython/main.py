from abc import ABC, abstractmethod

class persona(ABC):

    @abstractmethod
    def dice(self):
        pass

class estudiante(persona):

    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad
    
    def dice(self):
        print("mi nombre es " + self.nombre + " y tengo " + self.edad + " años")

erick = estudiante("erick", "19")

erick.dice()
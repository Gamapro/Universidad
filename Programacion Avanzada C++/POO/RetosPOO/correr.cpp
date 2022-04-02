#include "HeaderClases.h"
using namespace std;

int main(){
    
    Animal *animals[2];

    animals[0] = new Humano(18,"Gama");
    animals[1] = new Perro(10,"Juanito","Chihuahua");

    animals[0]->comer();
    animals[0]->mostrarDatos();

    animals[1]->comer();
    animals[1]->mostrarDatos();
}


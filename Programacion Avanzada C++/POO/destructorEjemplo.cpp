#include <iostream>
#include <string>
using namespace std;

class Perro{
private:
    string nombre;
public:
    Perro(string);
    void mostrarDatos();
    ~Perro();   // Destructor
};

// CONSTRUCTOR
Perro::Perro(string nombre){
    this->nombre = nombre;
}

// DESTRUCTOR
Perro::~Perro(){
    //delete[] nombre;
}

void Perro::mostrarDatos(){
    cout<<"Nombre: "<<nombre<<'\n';
}

int main(){
    Perro perro1 = Perro("Juanito");  
    perro1.mostrarDatos();
    perro1.~Perro(); // Destructor
}

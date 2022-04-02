#include <iostream>
#include <string>
using namespace std;

class Animal{
    private:
        int edad;
    public:
        Animal();
        Animal(int);
        virtual void comer();   // POLIMORFICA
        virtual void mostrarDatos();   // POLIMORFICA
        void setEdad(int);
        int getEdad();
};

Animal::Animal(){
    // nada
}

Animal::Animal(int edad){
    this->edad = edad;
}

void Animal::mostrarDatos(){
    cout<<"Tengo "<<this->getEdad()<<" años.\n";
}

void Animal::comer(){
    cout<<"Toy comiendo.\n";
}

void Animal::setEdad(int edad){
    this->edad = edad;
}

int Animal::getEdad(){
    return this->edad;
}



class Humano : public Animal{   // Herencia
    private:
        string nombre;
    public:
        Humano();
        Humano(int,string);    
        void comer();
        void setNombre(string);
        string getNombre();
        void mostrarDatos();
};

Humano::Humano(){
    // nada
}

Humano::Humano(int edad, string nombre) : Animal(edad){
    this->nombre = nombre;
}

void Humano::comer(){
    cout<<"Estoy comiendo en un restaurant porque soy humano.\n";
}

void Humano::mostrarDatos(){
    cout<<"Me llamo "<<nombre<<" y tengo "<<this->getEdad()<<" años.\n";
}

void Humano::setNombre(string nombre){
    this->nombre = nombre;
}

string Humano::getNombre(){
    return this->nombre;
}



class Perro : public Animal{   // Herencia
    private:
        string nombre;
        string raza;
    public:
        Perro();
        Perro(int,string,string);        
        void comer();
        void setNombre(string);
        string getNombre();
        void setRaza(string);
        string getRaza();
        void mostrarDatos();
};

Perro::Perro(){
    // nada
}

Perro::Perro(int edad, string nombre, string raza) : Animal(edad){
    this->nombre = nombre;
    this->raza = raza;
}

void Perro::comer(){
    cout<<"Estoy comiendo en mi tazoncito porque soy un perro.\n";
}

void Perro::mostrarDatos(){
    cout<<"Me llamo "<<nombre<<" y tengo "<<this->getEdad()<<" años. Mi raza es"<<raza<<"\n";
}

void Perro::setNombre(string nombre){
    this->nombre = nombre;
}

string Perro::getNombre(){
    return this->nombre;
}

void Perro::setRaza(string raza){
    this->raza = raza;
}

string Perro::getRaza(){
    return this->raza;
}


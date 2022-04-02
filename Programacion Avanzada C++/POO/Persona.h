#include <iostream>
#include <string>
using namespace std;

class Persona{
    
private:
    string nombre;
    int edad;

public:
    Persona();
    Persona(string, int);
    void comer();
    void leer();        
    void mostrarPersona();
};

// CONSTRUCTORES

Persona::Persona(){
    // nada
}

Persona::Persona(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}

void Persona::comer(){
    cout<<"Estoy comiendo\n";
}

void Persona::leer(){
    cout<<"Me llamo "<<nombre<<" y estoy leyendo\n";
}

void Persona::mostrarPersona(){
    cout<<"Me llamo "<<nombre<<" y tengo "<<edad<<" años.\n";
}


// HERENCIA ALUMNO

class Alumno : public Persona{   // Herencia
    private:
        string id;
        float calfFinal;
    public:
        Alumno();
        Alumno(string,int,string,float);        
        void mostrarAlumno();
};

Alumno::Alumno(){
    // NADA
}

Alumno::Alumno(string nombre, int edad, string id, float calfFinal) : Persona(nombre,edad){  // SUPERCONSTRUCTOR
    this->id = id;
    this->calfFinal = calfFinal;
}

void Alumno::mostrarAlumno(){
    mostrarPersona();
    cout<<"ID: "<<id<<", CalfFinal: "<<calfFinal<<'\n';
    return;
}



///  "HERENCIA MULTIPLE" mas o menos

class AlumnoUP : public Alumno{
    private:
        string carrera;
    public:
        AlumnoUP();
        AlumnoUP(string nombre, int edad, string id, float calfFinal, string carrera);
        void mostrarAlumnoUP();
        //void mostrarAlumno();
};

AlumnoUP::AlumnoUP(){
    // Nada
}

AlumnoUP::AlumnoUP(string nombre, int edad, string id, float calfFinal, string carrera) : Alumno(nombre, edad, id, calfFinal){
    this->carrera = carrera;
}

void AlumnoUP::mostrarAlumnoUP(){
    mostrarAlumno();
    cout<<"Carrera: "<<carrera<<'\n';
}


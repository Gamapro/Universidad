#include "Persona.h"
using namespace std;

int main(){
    Persona pedro = Persona("Pedro",20);    
    pedro.comer(); 
    pedro.leer();
    pedro.mostrarPersona();

    Alumno al = Alumno("Carlitos", 18, "0223827", 98.8);
    al.mostrarAlumno();

    AlumnoUP Gama("Gama",18,"0223826",10.0,"Inteligencia Artificial");
    Gama.mostrarAlumnoUP();

}


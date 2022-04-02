/* Escribir una plantila de funcion llamada despliegue que despliegue
el valor del argumento unico que se le transmite cuando es invocada la funcion*/

#include <iostream>
using namespace std;

template<class TIPOD>
void despliegue(TIPOD dato);

template<class TIPOD>
void despliegue(TIPOD dato){
    cout<<"EL dato es: "<<dato<<'\n';
}

int main(){

    int dint = 1;
    float dfloat = 5.6;
    double ddouble = 13.4434;
    char dchar = 'a';
    despliegue(dint);
    despliegue(dfloat);
    despliegue(ddouble);
    despliegue(dchar);

}


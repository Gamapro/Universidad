#include <iostream>
#include <string.h>
using namespace std;

struct Promedio{
    float nota[3];
    float promedio;

    Promedio(){
        for(int i = 0;i<3;i++){
            nota[i] = 0;
        }
        promedio = 0;
    }

    void imprimir(){
        for(int i = 0;i<3;i++){
            cout<<"Nota "<<i<<": "<<nota[i]<<"\n";
        }
        cout<<"Promedio: "<<promedio<<'\n';
    }

    void calcProm(){
        promedio = (nota[0]+nota[1]+nota[2])/3;
    }

};

struct Alumno{
    char nombre[20], sexo[10];
    int edad;
    struct Promedio prom; 

    void imprimir(){
        cout<<"Nombre: "<<nombre;
        cout<<", Sexo: "<<sexo;
        cout<<", Edad: "<<edad<<'\n';
        prom.imprimir(); 
        cout<<'\n';
        return;
    }
};

int n;
float mayor = 0;

int main(){
    cout<<"Ingrese el numero de alumnos: "; cin>>n;
    
    Alumno alumnos[n];

    for(int i=0;i<n;i++){
        cout<<"Alumno "<<i<<'\n';
        cout<<"Nombre:"; fflush(stdin); cin.ignore(); cin.getline(alumnos[i].nombre, 20, '\n');
        cout<<"Sexo:"; fflush(stdin); cin.ignore(); cin.getline(alumnos[i].sexo, 20, '\n');
        cout<<"Edad:"; cin>>alumnos[i].edad;
        cout<<"Notas\n";
        cout<<"Nota 1:"; cin>>alumnos[i].prom.nota[0];
        cout<<"Nota 2:"; cin>>alumnos[i].prom.nota[1];
        cout<<"Nota 3:"; cin>>alumnos[i].prom.nota[2];
        alumnos[i].prom.calcProm();
    }

    cout<<'\n';
    Alumno mejor;
    for(int i=0;i<n;i++){
        cout<<"Alumno "<<i<<'\n';
        alumnos[i].imprimir();
        if(alumnos[i].prom.promedio > mejor.prom.promedio)mejor = alumnos[i];
    }

    cout<<"EL alumno con el mejor promedio fue: \n";
    mejor.imprimir();
}

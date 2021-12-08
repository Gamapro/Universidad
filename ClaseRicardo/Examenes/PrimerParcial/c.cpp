#include <iostream>
#include <string>
using namespace std;

int n;

struct Promedio{
    float nota[2];
    float promedio;
    float fin,total;

    Promedio(){
        for(int i = 0;i<2;i++){
            nota[i] = 0;
        }
        promedio = fin = total = 0;
    }

    void imprimir(){
        for(int i = 0;i<2;i++){
            cout<<"Nota "<<i<<": "<<nota[i]<<"\n";
        }
        cout<<"Promedio: "<<promedio<<'\n';
        cout<<"Final: "<<fin<<'\n';
        cout<<"Total: "<<total<<'\n';
    }

    void calcProm(){
        promedio = (nota[0]+nota[1])/2;
        total = (promedio+fin)/2;
    }

};

struct Alumno{
    string id,nombre, sexo;
    struct Promedio prom; 

    void imprimir(){
        cout<<"Nombre: "<<nombre;
        cout<<", Sexo: "<<sexo;
        cout<<", ID: "<<id<<'\n';
        prom.imprimir(); 
        cout<<'\n';
        return;
    }
};

void showmax(Alumno alumnos[], int n){
    cout<<'\n';
    Alumno mejor = alumnos[0];
    for(int i=1;i<n;i++){
        if(alumnos[i].prom.total > mejor.prom.total) mejor = alumnos[i];
    }
    cout<<"El alumno con mejor calificacion final fue: \n";
    mejor.imprimir();
}

void showmin(Alumno alumnos[], int n){
    cout<<'\n';
    Alumno menor = alumnos[0];
    for(int i=1;i<n;i++){
        if(alumnos[i].prom.total < menor.prom.total) menor = alumnos[i];
    }

    cout<<"El alumno con menor calificacion final fue: \n";
    menor.imprimir();
}

int main(){
    
    cout<<"Ingrese el numero de alumnos: "; cin>>n;
    
    Alumno alumnos[n];

    for(int i=0;i<n;i++){
        cout<<"Alumno "<<i<<'\n';
        cout<<"Nombre: "; cin.ignore(); getline(cin,alumnos[i].nombre);
        cout<<"Sexo: "; getline(cin, alumnos[i].sexo);
        cout<<"ID: "; getline(cin,alumnos[i].id);
        cout<<"Notas\n";
        cout<<"Nota 1: "; cin>>alumnos[i].prom.nota[0];
        cout<<"Nota 2: "; cin>>alumnos[i].prom.nota[1];
        cout<<"Nota Final: "; cin>>alumnos[i].prom.fin;
        alumnos[i].prom.calcProm();
        alumnos[i].imprimir();
    }

    showmax(alumnos,n);
    showmin(alumnos,n);

}


#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Alumno{
private:
    int cal[3];
    int calFinal;
    int id;
public:
    Alumno();
    Alumno(int,int,int,int);
    int getFinal();
    void info();
};

Alumno::Alumno(){
    //nada
}

Alumno::Alumno(int _id, int c1, int c2, int c3){
    id = _id;
    cal[0] = c1;
    cal[1] = c2;
    cal[2] = c3;
    calFinal = (c1+c2+c3)/3;
}

void Alumno::info(){
    cout<<"ID: "<<id<<", Calf 1: "<<cal[0]<<", Calf 2: "<<cal[1]<<", Calf 3: "<<cal[2]<<", Calf Final: "<<calFinal<<'\n';
    return;
}

int Alumno::getFinal(){
    return calFinal;
}

int main(){
    srand (time(NULL));
    Alumno arr[10];
    int prom = 0, i= 0;
    for(Alumno &a : arr){
        a = Alumno(++i,rand()%6 + 5,rand()%6 + 5, rand()%6 + 5);   // VALORES ENTRE 5 Y 10
        prom+=a.getFinal();
        a.info();
    }
    prom/=10;
    cout<<"Promedio Alumnos: "<<prom<<'\n';
}

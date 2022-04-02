#include "tiempo.h"
#include <iostream>
using namespace std;

int totalSeg, horas, minutos, seg;

void tiempo(int totalSeg, int &horas, int &minutos, int &seg){
    horas+=totalSeg/3600; totalSeg%=3600;    
    minutos+=totalSeg/60; totalSeg%=60;
    seg = totalSeg;
    return;
}

int main(){
 
    cout<<"Ingrese una cantidad de segundos: "; cin>>totalSeg;
    tiempo(totalSeg, horas, minutos, seg);
    cout<<"Horas: "<<horas<<'\n';
    cout<<"Minutos: "<<minutos<<'\n';
    cout<<"Segundos: "<<seg<<'\n';

}



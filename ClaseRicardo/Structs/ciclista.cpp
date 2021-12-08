#include <iostream>
#include <string.h>
using namespace std;

struct Tiempo{
    int minutos, segundos, horas, segTotal;

    Tiempo(){
        minutos = segundos = horas = segTotal = 0;
    }

    void setTime(int time){
        segTotal = time;
        horas = time/3600;
        time%=3600;
        minutos = time/60;
        time%=60;
        segundos = time;
    }

    void imprimir(){
        cout<<"Horas: "<<horas<<", Minutos: "<<minutos<<", Segundos: "<<segundos<<'\n';
    }

    void addTime(Tiempo t){
        segTotal+= t.segTotal;
        setTime(segTotal);
    }
};

int n,x;

int main(){
    cout<<"Ingrese el numero de vueltas: "; cin>>n;
    
    Tiempo tiempos[n],fin;

    cout<<"Ingrese el tiempo por etapa en segundos.\n";
    for(int i=0;i<n;i++){
        cout<<"Etapa "<<i+1<<": "; cin>>x;
        tiempos[i].setTime(x);        
    }

    for(int i=0;i<n;i++){
        fin.addTime(tiempos[i]);
    }

    cout<<"El tiempo total fue: \n";
    fin.imprimir();
}


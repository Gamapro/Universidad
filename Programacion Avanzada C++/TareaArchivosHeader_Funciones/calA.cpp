#include "calcA.h"
#include <iostream>
using namespace std;

int cant, anio=2000, mes=1, dia=1;

void calc_anios(int cant, int &anio, int &mes, int &dia){
    anio+=cant/360; cant%=360;
    mes+=cant/30; cant%=30;
    dia+=cant;
    return;
}

int main(){
 
    cout<<"Ingrese una cantidad de dias: "; cin>>cant;
    calc_anios(cant,anio,mes,dia);
    cout<<"Fecha actual: "<<dia<<"/"<<mes<<"/"<<anio;
    cout<<'\n';

}



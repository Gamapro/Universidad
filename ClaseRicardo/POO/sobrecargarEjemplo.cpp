#include <iostream>
#include <string>
using namespace std;

class Fecha{
    
private:
    int dia, mes, anio;
public:
    Fecha(int, int, int);
    Fecha(long);
    void print();
};

Fecha::Fecha(int dia, int mes, int anio){
    this->dia = dia;
    this->anio = anio;
    this->mes = mes;
}

Fecha::Fecha(long fecha){
    // 2001/12/12
    anio = int(fecha/10000);
    mes = int((fecha/100)%100);
    dia = int(fecha%100);
}

void Fecha::print(){
    cout<<"Fecha\nAño: "<<anio<<", Mes: "<<mes<<", Dia: "<<dia<<'\n';
}


int main(){
    Fecha f1 = Fecha(31,8,2020);
    Fecha f2 = Fecha(20200830);
    f1.print();
    f2.print();

}


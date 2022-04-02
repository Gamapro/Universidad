#include <bits/stdc++.h>
using namespace std;

int cant, cien, cincuenta, veinte, diez, cinco, dos, uno;

void cambio(int cant, int &cien, int &cincuenta, int &veinte, int &diez, int &cinco, int &dos, int &uno){
    cien+=cant/100; cant%=100;
    cincuenta+=cant/50; cant%=50;
    veinte+=cant/20; cant%=20;
    diez+=cant/10; cant%=10;
    cinco+=cant/5; cant%=5;
    dos+=cant/2; cant%=2;
    uno+=cant;
    return;
}

int main(){

    cout<<"Ingrese una cantidad: "; cin>>cant;
    cambio(cant, cien, cincuenta, veinte, diez, cinco, dos, uno);
    cout<<"Cantidad en billetes/monedas.\n";
    cout<<"100$: "<<cien<<'\n';
    cout<<"50$: "<<cincuenta<<'\n';
    cout<<"20$: "<<veinte<<'\n';
    cout<<"10$: "<<diez<<'\n';
    cout<<"5$: "<<cinco<<'\n';
    cout<<"2$: "<<dos<<'\n';
    cout<<"1$: "<<uno<<'\n';
}



#include "potencia.h"
#include <iostream>
using namespace std;

int x,y;

int pot(int x, int y){
    if(y <= 0) return 1;
    return x*pot(x,y-1);
}

int main(){
 
    cout<<"Ingrese un numero entero: "; cin>>x;
    cout<<"Ingrese la potencia entera a elevar el numero: "; cin>>y;
    int res = pot(x,abs(y));
    cout<<x<<"^"<<y<<" = "<<res;
    cout<<'\n';

}




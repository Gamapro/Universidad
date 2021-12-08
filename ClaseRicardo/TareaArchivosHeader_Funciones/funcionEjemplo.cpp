#include "myLib.h"
#include <iostream>
using namespace std;

int square(int a){
    return a*a;
}

int cube(int a){
    return square(a)*a;
}

int main(){
    
    int a,b;
    cout<<"Digite un numero 'a': "; cin>>a;
    cout<<"Digite un numero 'b': "; cin>>b;
    cout<<"Su numero a elevado al cuadrado es: "<<square(a)<<'\n';
    cout<<"Su numero b elevado al cubo es: "<<cube(b)<<'\n';

}

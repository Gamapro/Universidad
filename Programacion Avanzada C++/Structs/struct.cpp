#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct corredor{
    char nombre[20], sexo[10], club[20];
    int edad;
}c1;

int main(){

    char categoria[10];

    cout<<"Ingrese Nombre: ";
    cin.getline(c1.nombre,20,'\n');  

    cout<<"Ingrese Edad: ";
    cin>>c1.edad;

    fflush(stdin); // LIMPIAR EL BUFFER
    cout<<"Ingrese Sexo: ";
    // cin.ignore();
    fflush(stdin); // LIMPIAR EL BUFFER
    cin.getline(c1.sexo,10,'\n');  

    cout<<"Ingrese Club: ";
    cin.getline(c1.club,20,'\n');  

    if(c1.edad <= 18){
        strcpy(categoria,"Juvenil");
    }else if(c1.edad <= 40){
        strcpy(categoria,"Senior");
    }else{
        strcpy(categoria,"Veterano");
    }

    cout<<"Nombre: "<<c1.nombre<<'\n';
    cout<<"Edad: "<<c1.edad<<'\n';
    cout<<"Sexo: "<<c1.sexo<<'\n';
    cout<<"Club: "<<c1.club<<'\n';
    cout<<"Categoria: "<<categoria<<'\n';
}

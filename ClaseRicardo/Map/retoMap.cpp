#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <fstream>
using namespace std;

class Registro{
public:
    string nombre, apellido, tel;

    Registro(){}

    Registro(string nombre, string apellido, string tel){
        this->nombre = nombre;
        this->apellido = apellido;
        this->tel = tel;
    }

    void print() const{
            cout<<"\nNombre: "<<nombre;
            cout<<"\nApellido: "<<apellido;
            cout<<"\nTelefono: "<<tel<<'\n';
    }

    string to_str(){
        string s="";
        s+="\nNombre: "+nombre;
        s+="\nApellido: "+apellido;
        s+="\nTelefono: "+tel+"\n";
        return s;
    }

    bool operator<(const Registro &r) const{
        return (nombre!=r.nombre)?nombre<r.nombre:(apellido!=r.apellido?apellido<r.apellido:(tel<r.tel));
    }

};

int main(){

    int op;
    map<Registro,bool> v;
    int k=0;
    while(1){
        cout<<"OPCIONES:\n1. Crear(nombre, apellidos, teléfono) y agregar a la lista\n";
	    cout<<"2. Agregar mas contactos(nombre, apellidos, teléfono)\n";
	    cout<<"3. Visualizar contactos existentes\n";
	    cout<<"4. Salir\n";
        cin>>op;
        if(op == 1 || op == 2){
            string nombre, apellido, tel;
            cout<<"Ingrese los datos(nombre, apellidos, teléfono)\n";
            cout<<"Nombre: "; cin>>nombre;
            cout<<"Apellido: "; cin>>apellido;
            cout<<"Telefono: "; cin>>tel;
            Registro r(nombre,apellido,tel);
            v[r] = true;
 
            ofstream f;
            string salida = "Registro No. "+to_string(k++)+".txt";
            f.open(salida,ios::out);

            f << r.to_str();

            f.close();


        }else if(op == 3){
            cout<<"Inicio Registros Actuales:\n";
            for(auto &r : v){
                r.first.print();
            }
            cout<<"\nFin Registros Actuales:\n";
        }else if(op == 2){
            
        }else if(op == 4){
            cout<<"Gracias :D\n";
            return 0;
        }else{  
            cout<<"Intente nuevamente\n";
        }
    }
}


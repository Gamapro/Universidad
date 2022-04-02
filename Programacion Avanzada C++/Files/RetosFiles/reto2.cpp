#include <iostream>
#include <vector>
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

    void print(){
            cout<<"\nNombre: "<<nombre;
            cout<<"\nApellido: "<<apellido;
            cout<<"\nTelefono: "<<tel<<'\n';
    }

};

void escribir(){
 
    ifstream f1,f2;
    ofstream f3;
    string n1,n2,texto;
    string salida = "salida.txt";

    cout<<"Digite el nombre del primer archivo: ";
    getline(cin,n1);
    f1.open(n1,ios::in);

    if(f1.fail()){  // Funcion que regresa un booleano, si el archivo pudo o no abrirse 
        cout<<"Error al abrir el primer archivo.\n";       
        f1.close();
        return;
    }

    cout<<"Digite el nombre del segundo archivo: ";
    getline(cin,n2);
    f2.open(n2,ios::in);

    if(f2.fail()){  // Funcion que regresa un booleano, si el archivo pudo o no abrirse 
        cout<<"Error al abrir el segundo archivo.\n";       
        f1.close();
        f2.close();
        return;
    }

    f3.open(salida,ios::out);

    

    f1.close();
    f2.close();
    f3.close();

}

int main(){

    int op;
    vector<Registro> v;
    while(1){
        cout<<"OPCIONES:\n1. Crear(nombre, apellidos, teléfono) y agregar a la lista\n";
	    cout<<"2. Visualizar contactos existentes\n";
	    cout<<"3. Salir\n";
        cin>>op;
        if(op == 1){
            string nombre, apellido, tel;
            cout<<"Ingrese los datos(nombre, apellidos, teléfono)\n";
            cout<<"Nombre: "; cin>>nombre;
            cout<<"Apellido: "; cin>>apellido;
            cout<<"Telefono: "; cin>>tel;
            Registro r(nombre,apellido,tel);
            v.push_back(r);
        }else if(op == 2){
            cout<<"Inicio Registros Actuales:\n";
            for(int i=0;i<v.size();i++){
                v[i].print();
            }
            cout<<"\nFin Registros Actuales:\n";
        }else if(op == 3){
            cout<<"Gracias :D\n";
            return 0;
        }else{  
            cout<<"Intente nuevamente\n";
        }
    }
}


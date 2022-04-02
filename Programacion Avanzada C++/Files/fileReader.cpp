#include <iostream>
#include <fstream>
using namespace std;

void leer();

int main(){
    
     leer();

}

void leer(){
 
    ifstream file;
    string nombreArchivo, texto;

    cout<<"Digite el nombre del archivo: ";
    getline(cin,nombreArchivo);
    file.open(nombreArchivo,ios::in);

    if(file.fail()){  // Funcion que regresa un booleano, si el archivo pudo o no abrirse 
        cout<<"Error al abrir el archivo.\n";       
        file.close();
        return;
    }

    while(!file.eof()){  // Funcion que dice si el archivo llego al EOF
        getline(file,texto);
        cout<<texto<<'\n';
    }

    file.close();

}

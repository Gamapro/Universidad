#include <iostream>
#include <fstream>
using namespace std;

void escribir();

int main(){
    
     escribir();

}

void escribir(){
 
    ofstream file;
    string nombreArchivo, texto;

    cout<<"Digite el nombre del archivo: ";
    getline(cin,nombreArchivo);
    file.open(nombreArchivo,ios::out);

    if(file.fail()){  // Funcion que regresa un booleano, si el archivo pudo o no abrirse 
        cout<<"Error al abrir el archivo.\n";       
        file.close();
        return;
    }

    char res='S';

    do{
        fflush(stdin);
        cout<<"Digite una linea a escribir: ";
        cin.ignore();
        getline(cin,texto);
        file << texto << '\n';
        cout<<"Desea agregar otra frase (S/N): ";
        cin>>res;
    }while(res == 'S' || res == 's');

    file.close();

}

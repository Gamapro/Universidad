#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Persona{
    string nombre;
    bool discapacidad;
};

int n;

int main(){    

    cout<<"Ingrese el numero de personas: "; cin>>n;
    
    Persona p[n];
    vector<Persona> si,no;
    cout<<"Ingrese el nombre de la persona y si tiene alguna discapacidad digite 1, de no tenerla digite 0.\n";
    for(int i=0;i<n;i++){
        cout<<"Persona"<<i+1<<"\nNombre: "; cin>>p[i].nombre;
        cout<<"Discapacidad?: "; cin>>p[i].discapacidad;
        if(p[i].discapacidad) si.push_back(p[i]);
        else no.push_back(p[i]);
    }
    
    cout<<"\nPersonas sin ninguna discapacidad:\n";
    for(int i=0;i<no.size();i++){
        cout<<no[i].nombre<<'\n';
    }

    cout<<"\nPersonas con alguna discapacidad:\n";
    for(int i=0;i<si.size();i++){
        cout<<si[i].nombre<<'\n';
    }


}

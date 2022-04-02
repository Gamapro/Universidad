#include <bits/stdc++.h>
using namespace std;

class cosa{
public:

    int edad;
    string nombre;
    
    cosa(){}

    cosa(string nombre, int edad){
        this->nombre = nombre;
        this->edad = edad;
    }

    void print() const{
        cout<<"Edad: "<<edad<<", Nombre: "<<nombre<<'\n';
    }

    bool operator<(const cosa &t2) const{
        if(edad != t2.edad) return edad < t2.edad;
        else return nombre < t2.nombre;
    }

};

int main(){

    set<cosa> s;
    int n = 9;
    for(int i = 0;i<n;i++) s.insert(cosa("sara",i));

    for(set<cosa>::iterator it = s.begin(); it != s.end(); ++it){
        it->print();
    }

}

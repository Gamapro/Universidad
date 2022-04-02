#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Articulo{
private:
    string nombre,descripcion;
    bool nacionalidad;
    double precio;
public:
    Articulo();
    Articulo(string,string,bool,double);
    void info();
    void setNacionalidad(bool);
    bool getNacionalidad();
    double getPrecio();
    void desc();
};

Articulo::Articulo(){
    //nada
}

Articulo::Articulo(string _nom, string des, bool nacio, double _precio){
    nombre = _nom;
    descripcion = des;
    nacionalidad = nacio;
    precio = _precio;
}

void Articulo::setNacionalidad(bool que){
    nacionalidad = que;
}

bool Articulo::getNacionalidad(){
    return nacionalidad;
}

double Articulo::getPrecio(){
    return precio;
}

void Articulo::info(){
    cout<<"Nombre: "<<nombre<<", Descripcion: "<<descripcion<<", Nacionalidad Mexicana: "<<nacionalidad<<", Precio: "<<precio<<'\n';
    return;
}

void Articulo::desc(){
    if(nacionalidad){
        precio = precio*1.16;
    }
}

int main(){
    srand (time(NULL));
    Articulo arr[30];
    double sum = 0;
    for(Articulo &a : arr){
        a = Articulo("","",bool(rand()%2),double(int(rand()%100 + 1)));
        a.info();
        a.desc();
        sum+=a.getPrecio();
    }
    cout<<"Monto total: "<<sum<<'\n';
}


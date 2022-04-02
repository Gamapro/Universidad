#include <iostream>
#include <string>
using namespace std;

class Rectangulo{

private:
    float largo, ancho;
public:
    Rectangulo();
    Rectangulo(float, float);
    void perimetro();
    void area();
    void datos();
};

Rectangulo::Rectangulo(){

}

Rectangulo::Rectangulo(float largo, float ancho){
    this->largo = largo;
    this->ancho = ancho;
}

void Rectangulo::perimetro(){
    cout<<"Perimetro: "<<2*(largo+ancho)<<'\n';
}

void Rectangulo::area(){
    cout<<"Area: "<<largo*ancho<<'\n';
}

void Rectangulo::datos(){
    cout<<"Largo: "<<largo<<", Ancho: "<<ancho<<'\n';
}

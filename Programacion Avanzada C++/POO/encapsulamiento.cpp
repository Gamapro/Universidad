#include <iostream>
#include <string>
using namespace std;

class Punto{
    private:
        int x,y;
    public:
        Punto();
        Punto(int x, int y);
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        void setXY(int, int);
}

Punto::Punto(){
    // Constructor vacio
}

Punto::Punto(int x, int y){
    this->x = x;
    this->y = y;
}

int Punto::getX(){
    return x;
}

int Punto:getY(){
    return y;
}

void Punto::setX(int x){
    this->x = x;
}

void Punto::setY(int y){
    this->y = y;
}

void Punto::setXY(int x,int y){
    this->x = x;
    this->y = y;
}

int main(){
    Punto p;
    Punto points[10];
    p.setXY(1,1);
}

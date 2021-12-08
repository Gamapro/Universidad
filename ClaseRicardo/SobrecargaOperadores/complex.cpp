#include "Complex.h"

namespace advanced_programming{
    Complex::Complex(): real(0), imaginary(0) {}
    Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {}
    Complex::Complex(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;
    }
    Complex::~Complex(){ 
        //cout<<"Delete "<<*this; 
    }
    
    Complex& Complex::operator=(const Complex &other){
        setReal(other.real);
        setImaginary(other.imaginary);
        return *this;
    }

    Complex& Complex::operator+=(const Complex& a){
        setReal(this->getReal()+a.getReal());
        setImaginary(this->getImaginary()+a.getImaginary());
        return *this;
    }

    Complex& Complex::operator-=(const Complex& a){
        setReal(this->getReal()-a.getReal());
        setImaginary(this->getImaginary()-a.getImaginary());
        return *this;
    }

    Complex& operator+(const Complex& a, const Complex& b){
        return *(new Complex(a.getReal()+b.getReal(), a.getImaginary() +b.getImaginary()));
    }

    Complex& operator-(const Complex& a, const Complex& b){
        return *(new Complex(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary()));
    }

    ostream &operator<<(ostream &out, const Complex &c){
        out << "Real: "<<c.getReal()<<", Imaginary: "<<c.getImaginary()<<'\n';
        return out;
    }

}

using namespace advanced_programming;

int main(){
    
    Complex a(1,2), b(3,4); 
    cout<<a<<b; 
    Complex c = a+b, d = a-b;
    cout<<c<<d;
    a = b;
    cout<<a<<b; 
    a-=b;
    c+=d;
    cout<<a<<c;
}

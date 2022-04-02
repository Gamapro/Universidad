#include <iostream>
using namespace std;

namespace advanced_programming {

    class Complex {
    private:
        double real;
        double imaginary;

    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(const Complex &other);
        ~Complex();
        Complex &operator=(const Complex &other);

        Complex& operator+=(const Complex& a);
        Complex& operator-=(const Complex& a);

        double getReal() const {
            return real;
        }
        double getImaginary() const {
            return imaginary;
        }

        void setReal(double real){
            this->real = real;
        }

        void setImaginary(double imaginary){
            this->imaginary = imaginary;
        }
        
    };

    Complex& operator+(const Complex& a, const Complex& b);
    Complex& operator-(const Complex& a, const Complex& b);

    ostream &operator<<(ostream &out, const Complex &c);

}

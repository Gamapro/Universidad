#include <iostream>
#include <string>
using namespace std;

struct Fraccion{
    int a,b;
};

int mcd(int a, int b){
    if(b==0)return a;
    else return mcd(b,a%b);
}

int main(){

    Fraccion a,b;

    cout<<"Enter fraction 1(numerator denominator): ";
    cin>>a.a>>a.b;

    cout<<"Enter fraction 2(numerator denominator): ";
    cin>>b.a>>b.b;

    int x,y,z;
    x = a.a*b.b + b.a*a.b;
    y = a.b * b.b;
    z = mcd(x,y);
    x/=z; y/=z;
    Fraccion r;
    r.a = x; r.b = y;

    cout<<"Result: "<<r.a<<"/"<<r.b<<"\n";
}


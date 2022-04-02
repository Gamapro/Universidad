#include<iostream>
#include<string>
using namespace std;

class Test{
public:

    int id;
    string name;

    Test() : id(0), name(""){}
    Test(int id, string name) : id(id), name(name){}
    void print(){
        cout<<"ID: "<<id<<", Name: "<<name<<'\n';
    }

//const  nombreClase   tipoDeOperador       Argumentos
// const  Test&            operator=     (const Test& t){
    const Test& operator=(const Test& t){
        this->id = t.id;
        this->name = t.name;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Test &t){
        out<<"ID: "<<t.id<<", Name: "<<t.name<<'\n';
        return out;
    }

    bool operator<(const Test &t){
        if(id == t.id){
            return name < t.name;
        }else{
            return id < t.id;
        }
    }

    Test& operator+=(const Test& t) { //Sobrecarga del operador '+'
		id+=t.id,name+=t.name;
        return *this;
	}

};

int main(){

   Test t1(12,"Pedro");
   Test t2(20,"Claudio");

    cout<<t1<<t2;

    t2 = t1;

    cout<<t1<<t2;
    
    t1+=t2;

    cout<<t1<<t2;

}

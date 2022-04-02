#include <iostream>
#include <thread>
using namespace std;

void foo(int a){
    cout<<a<<'\n';
}

int main(){
    //Crear thread y ejecutando en otro hilo
    thread t(foo, 10);  // (nombre, args)
    t.join();
    return 0;
}


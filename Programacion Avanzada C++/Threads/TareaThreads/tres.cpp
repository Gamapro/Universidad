#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define n_threads 5
int n;
thread t[n_threads];

void print_arr(int arr[], const int n, const string cual){
    cout<<cual<<" [";
    for(int i=0;i<n;i++){
        if(i)cout<<", ";
        cout<<arr[i];
    }
    cout<<"]\n";
}

void iterar(int n, int x){
    this_thread::sleep_for(chrono::milliseconds(n*1000));
    cout<<"Ciclo "<<x<<" duró "<<n<<" segundos :)"<<'\n';
}


int main(){
    srand (time(NULL));
    cout<<"Ingrese el numero de hilos a ejecutar. (Maximo 5)\n";
    cin>>n;
    if(n>5){
        cout<<"Intente con un numero menor.\n";
        return 0;
    }
    cout<<"Ingrese las duraciones de los "<<n<< " hilos en segundos: ";
    int dur[n];
    for(int i=0;i<n;i++){
        cin>>dur[i];
    }
    for(int i=0;i<n;i++){
        t[i] = thread(iterar, dur[i], i+1);
    } 
    for(int i=0;i<n;i++){
        t[i].join();
    } 
}

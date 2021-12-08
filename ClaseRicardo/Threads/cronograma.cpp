#include <iostream>
 23     for(int i=0;i<n_threads;i++){
 24         t[i] = thread(print, i, nombre[i]);
 25         t[i].join();
 26     }
#include <string>
#include <thread>
#include <chrono>
using namespace std;

#define n_threads 3

void print(int n, const string &s){
    string msg = to_string(n) + ": "+s+"\n";
    cout<<msg;
    this_thread::sleep_for(chrono::milliseconds(1000));
    return;
}

thread t[n_threads];

int main(){
   
    string nombre[n_threads] = {"Juan", "Delgadillo", "Lopez"};


    for(int i=0;i<n_threads;i++){
        t[i] = thread(print, i, nombre[i]);    
        t[i].join();
    }

    for(int i=0;i<n_threads;i++){
    }

    cout<<"Main gg\n";

}

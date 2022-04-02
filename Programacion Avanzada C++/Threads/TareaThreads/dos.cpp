#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define n_threads 2
const int n = 10;
thread t[n_threads];

void print_arr(int arr[], const int n, const string cual){
    cout<<cual<<" [";
    for(int i=0;i<n;i++){
        if(i)cout<<", ";
        cout<<arr[i];
    }
    cout<<"]\n";
}

void iterar(int n){
    for(int i=0;i<n;i++){}
    cout<<n<<'\n';
}


int main(){
    srand (time(NULL));
        
    for(int i=0;i<n_threads;i++){
        int x = rand()%100;
        t[i] = thread(iterar, x);
    } 
    for(int i=0;i<n_threads;i++){
        t[i].join();
    } 
    
}

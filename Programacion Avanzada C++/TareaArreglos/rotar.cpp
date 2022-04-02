#include <iostream>
#include <stdlib.h>
using namespace std;

int n,k;
int arr[10000];
int arr2[10000];

int main (){

    cout<<"Ingrese el numero de elementos: ";
    cin>>n;
    cout<<"Ingrese los elementos: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Ingrese el numero de pasos a rotar: ";
    cin>>k;

    cout<<"El nuevo arreglo es:\n";
    for(int i=0;i<n;i++){
        arr2[i] = arr[(i-k+n)%n];
        cout<<arr2[i]<<' ';
    }

    cout<<'\n'; 

    return 0;
}


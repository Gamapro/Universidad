#include <iostream>
#include <cstring>
//#include <stdlib.h>
using namespace std;

int n;
int arr[10000];
int vec[10000];

int decreciente(){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return 1;
        }
    }   
    return 0; 
}

int checar(){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            // Mayor
            int previo = arr[i];
            arr[i] = arr[i-1];
            if(!decreciente()){
                return 1;
            }
            // Menor
            arr[i] = arr[i-1] = previo; 
            if(!decreciente()){
                return 1;
            }
            return 2;
        }
    }   
    return 0; 
}

int main (){

    cout<<"Ingrese el numero de elementos: ";
    cin>>n;
    cout<<"Ingrese los elementos: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int res = checar();
    if(res == 0){
        cout<<"El arreglo ya es no decreciente."<<'\n'; 
    }else if(res == 1){
        cout<<"El arreglo necesito una operacion para volverse no decreciente."<<'\n'; 
    }else if(res == 2){
        cout<<"El arreglo necesita mas de una operacion para volverse no decreciente."<<'\n'; 
    }

    cout<<"Arreglo Final:";
    for(int i=0;i<n;i++){
        cout<<' '<<arr[i];
    }
    cout<<'\n';
    return 0;
}


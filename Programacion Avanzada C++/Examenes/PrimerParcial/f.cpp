#include <iostream>
#include <string>
using namespace std;

int n,m,d,cont;

int main(){
    cout<<"Ingresa el numero de datos del primer arreglo: ";
    cin>>n;
    int arr[n];
    cout<<"Ingresa los datos: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Ingresa el numero de datos del segundo arreglo: ";
    cin>>m;
    int arr2[m];
    cout<<"Ingresa los datos: ";
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    cout<<"Ingresa d: ";
    cin>>d;

    for(int i=0;i<n;i++){
        bool ya = false;
        for(int j=0;j<m;j++){
           if(abs(arr[i]-arr2[j]) <= d)ya=true;
        }
        if(!ya)cont++;
    }
    
    cout<<"Distancia: "<<cont<<'\n';

}

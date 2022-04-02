#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int n,x,k;
    cout<<"Ingrese el numero de elementos: ";
    cin>>n; 
    cout<<"Ingrese los elementos: ";
    vector<int> v,v2;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        v2.push_back(0);
    }
    cout<<"Ingrese los pasos a rotar: ";
    cin>>k;

    
    for(int i=0;i<n;i++){
        v2[(i+k)%n] = v[i];
    }

    cout<<"El arreglo recorrido es: ";
    for(int i=0;i<n;i++){
        cout<<v2[i]<<' ';
    }
    cout<<'\n';
}


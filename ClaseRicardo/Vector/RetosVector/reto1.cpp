#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int n,x;
    cout<<"Ingrese el numero de elementos: ";
    cin>>n; 
    cout<<"Ingrese los elementos: ";
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        v[i]*=v[i];
    }
    sort(v.begin(), v.end());
    
    cout<<"Los cuadrados son: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}


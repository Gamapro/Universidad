#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int n,x,k;
    cout<<"Ingrese el numero de elementos: ";
    cin>>n; 
    cout<<"Ingrese los elementos: ";
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    
    bool si = false;
    bool as=false;
    int d=0,iz=n-1;
    for(int i=0;i<n-1;i++,d++){
        if(v[i+1] <= v[i]){
            break;
        }
    }
    for(int i=n-1;i>0;i--,iz--){
        if(v[i-1] <= v[i]){
            break;
        }
    }
    if(iz == d && d!=n-1 && d != 0)cout<<d;
    else cout<<"NO es montaña.";
    cout<<'\n';

}


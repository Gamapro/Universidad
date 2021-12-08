#include <bits/stdc++.h>
using namespace std;

int n,a,b,c;
vector<int> v;

int f(){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n;j++){
            for(int k=j+1;k<n;k++){
                if(abs(v[i] - v[j]) > a) continue;
                if(abs(v[j] - v[k]) > b) continue;
                if(abs(v[i] - v[k]) > c) continue;
                ans++;
            }
        }
    }
    return ans;
}

int main(){

    cout<<"Ingrese el numero de elementos: "; cin>>n;
    v.assign(n,0);
    cout<<"Ingrese el numero a: "; cin>>a;
    cout<<"Ingrese el numero b: "; cin>>b;
    cout<<"Ingrese el numero c: "; cin>>c;
    
    cout<<"Ingrese los elementos: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<f();
    cout<<'\n';

}

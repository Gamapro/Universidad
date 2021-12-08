#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

//int arr[] = {2,7,11,15,8,5};
int arr[] = {5,7,8,4,2};
int obj = 9;
int sol[2] = {0,0};

void sumaDosElementos(int obj){
    sol[1] = obj;
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0;i<n;i++){
        if(arr[i]<obj){
            for(int j=i+1;j<n;j++){
                if(arr[i] + arr[j] == obj){
                    sol[0] = arr[i];
                    sol[1] = arr[j];
                    return;
                }
            }
        }
    }
    return;
}

int main(){
    cout<<"El arreglo es:"; 
    for(int x : arr){ cout<<' '<<x; } cout<<'\n';
    cout<<"El objetivo es: "<<obj<<'\n';
    sumaDosElementos(obj);
    cout<<"Las soluciones son :";
    for(int x : sol){ cout<<' '<<x; } cout<<'\n';
    cout<<'\n';
}


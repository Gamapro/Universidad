#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

//int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
int arr[] = {7,-1,-4,-1,2,-10,12,-4,2,3};
int n = sizeof(arr)/sizeof(int);
int a,b,suma,mayor;

int maxSum(){
    suma = mayor = a = b =0;
    for(int i=0;i<n;i++){
        suma+=arr[i];
        suma = max(suma,0);
        mayor = max(mayor,suma);
    }
    return mayor;
}

int main(){
    cout<<"El arreglo es:"; 
    for(int x : arr){ cout<<' '<<x; } cout<<'\n';
    int sol = maxSum();
    cout<<"La suma maxima es: "<<sol;
    cout<<'\n';

}



#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int arr[] = {2,3,5,7,10,21,45,46,56,78,98,100,101,122,123,124};

int busca(int x, int n){
    int salto=-1, aum = n;
    while(aum){
        if(salto+aum <= n && arr[salto+aum] < x) salto+=aum;
        else aum/=2;
    }
    return salto+1;
}

int main(){
    cout<<"El arreglo ordenado es:"; 
    for(int x : arr){ cout<<' '<<x; } cout<<'\n';
    int obj = 11;
    cout<<"El objetivo es: "<<obj<<'\n';
    int n = sizeof(arr)/sizeof(int);
    int sol = busca(obj,n);
    if(arr[sol] == obj){
        cout<<"El objetivo fue encontrado en el index "<<sol;
    }else{
        cout<<"El objetivo deberia estar en el index "<<sol;
    }
    cout<<'\n';

}


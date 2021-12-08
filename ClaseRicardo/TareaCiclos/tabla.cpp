#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){
	
	int x;
	cout<<"Ingrese el valor de la tabla a imprimir: ";
	cin>>x; 
    cout<<'\n';

    for(int i = 0;i<x*8;i++)cout<<"-"; cout<<"---\n";
	for(int i=1;i<=x;i++){
        cout<<i<<"* ";
        for(int j=1;j<=x;j++){
            cout<<'\t'<<i*j;
        }
        cout<<'\n';
	}
    cout<<'\n';
}




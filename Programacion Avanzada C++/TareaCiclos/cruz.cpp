#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){
	
	int x,a,b;
	cout<<"Ingrese la altura de la cruz a imprimir: ";
	cin>>x; cout<<'\n';
    a=0; b=x-1;
	for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<((a==j||b==j)?'*':' ');
        }
        a++; b--; 
        cout<<'\n';
	}
    cout<<'\n';
}



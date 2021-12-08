#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){
	
	int x,factor = 1; 
	cout<<"Ingrese un numero para determinar su factor mas grande: ";
	cin>>x;
	for(int i=2;i*i<=x;i++){
		if(x%i == 0){
			factor = x/i;		
			break;
		}
	}
    cout<<"El factor mas grande es: "<<factor<<'\n';
}


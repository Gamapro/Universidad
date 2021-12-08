#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

bool esPrimo(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){

	int suma = 0;
	for(int i=1; i<=10000; i++){
		if(esPrimo(i)){
			// cout<<i<<" ";
			suma+=i;
		}
	}
	cout<<"La sumatoria de los numeros primos entre 0 y 10000 es: "<<suma;
	cout<<'\n';
	
}


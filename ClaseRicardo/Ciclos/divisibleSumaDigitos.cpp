#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){

	int x,suma=0;
	cout<<"Digita un numero: ";
	cin>>x;
	while(x){
		suma += x%10;
		x/=10;
	}
	cout<<"La sumatoria de sus digitos es "<<suma<<'\n';
	
	cout<<"Los numeros divisibles entre la sumatoria de los digitos de tu numero son:";

	for(int i = 1; i<=10000; i++){
		if(i%suma == 0){
			cout<<" "<<i;
		}
	}

	cout<<'\n';
	
}


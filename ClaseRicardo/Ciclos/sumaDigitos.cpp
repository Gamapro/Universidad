#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){

	int x,suma=0;
	cout<<"Digita un numero para darte la sumatoria de sus digitos: ";
	cin>>x;
	while(x){
		suma += x%10;
		x/=10;
	}
	cout<<"La sumatoria es "<<suma<<'\n';
}


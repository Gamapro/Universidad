#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){
	
	int h,w;
	cout<<"Ingrese la altura del patron a imprimir: ";
	cin>>h; 
    cout<<"Ingrese la altura del patron a imprimir: ";
	cin>>w; 
    cout<<'\n';

	for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<((i%2==0)?'*':((j&1)?'0':'*'));
        }
        cout<<'\n';
	}
    cout<<'\n';
}




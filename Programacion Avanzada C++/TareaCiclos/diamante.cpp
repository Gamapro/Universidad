#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){
	
	int x,a,aa=-1,ab=1,b;
	cout<<"Ingrese la altura del diamante a imprimir: ";
	cin>>x; cout<<'\n';
    a=b=x/2;
    if(x%2==0)a--;
	for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<((a==j||b==j)?'*':' ');
        }
        a+=aa; b+=ab;
        if(a<0){ 
            if(x&1){a=1;b=x-2;}
            else{ a=0; b=x-1; } 
            aa=1; ab=-1; 
        }
        cout<<'\n';
	}
    cout<<'\n';
}



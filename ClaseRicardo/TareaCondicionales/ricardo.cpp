#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';

int main(){

    /*int x;
    cout<<"INTRODUZCA EL NUMERO Y LE DIGO SI ES PAR O NO :P\n";
    cin>>x;
    cout<<"EL NUMERO "<<((x&1)?" NO ":"")<<"ES PAR.\n";    */

    /*char c;
    cout<<"INTRODUZCA EL CARACTER Y LE DIGO SI ES MAYUSCULA O NO :P\n";
    cin>>c;
    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o')
        cout<<"Es vocal minuscula\n";
    else if(c=='A'||c=='I'||c=='U'||c=='E'||c=='O')
        cout<<"Es vocal mayuscula\n";
    else
        cout<<"No es vocal :(\n";		*/

	/*int a,b,c,x;
	cout<<"Dame 3 numeros prro\n";
	cout<<"Numero 1: "; cin>>a;
	cout<<"Numero 2: "; cin>>b;
	cout<<"Numero 3: "; cin>>c;
	cout<<"Dame un numero para comparar prro\n";
	cout<<"Numero a comparar: "; cin>>x;
	cout<<"Tus primeros 3 numeros: "<<a<<" "<<b<<" "<<c<<'\n';
	cout<<"Tu ultimo numero ingresado: "<<x<<'\n';
	if(a==x||b==x||c==x){
		cout<<"Tu numero coincide con alguno de los ingresados\n";
	}else{
		cout<<"Tu numero no coincide, ctm\n";
	}		*/

	int x,a,b,c;
	cout<<"Dame un numero para pasartelo a romano porfa\n";
	cin>>x;
	string s="El resultado es: ";
	string p = "IVXLCDM";
	int index = p.size()-1;
	int pot = 1000;
	map<char,int> mapa;

	while(pot){
		// POT 10
		a = x/pot;
		b = x%pot;
		while(a--){ mapa[p[index]]++; }
		x = b; index-=2;
		pot/=10;
	}

	reverse(p.begin(),p.end());
	for(char c : p){
		int val = mapa[c];
		if(c == 'M'){
			while(val--)s+=c;
		}else if(c == 'C'){
			if(val>0&&val<4){
				while(val--)s+=c;
			}else if(val == 4){
				s+="CD";
			}else if(val>=5 && val <=8){
				s+='D'; val-=5;
				while(val--)s+=c;
			}else if(val==9){
				s+="CM";
			}
		}else if(c == 'X'){
			if(val>0&&val<4){
				while(val--)s+=c;
			}else if(val == 4){
				s+="XL";
			}else if(val>=5 && val <=8){
				s+='L'; val-=5;
				while(val--)s+=c;
			}else if(val==9){
				s+="XC";
			}
		}else if(c == 'I'){
			if(val>0&&val<4){
				while(val--)s+=c;
			}else if(val == 4){
				s+="IV";
			}else if(val>=5 && val <=8){
				s+='V'; val-=5;
				while(val--)s+=c;
			}else if(val==9){
				s+="IX";
			}
		}	
	}

	cout<<s<<'\n';

}   

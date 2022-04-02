#include <bits/stdc++.h>
using namespace std;

int main(){

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


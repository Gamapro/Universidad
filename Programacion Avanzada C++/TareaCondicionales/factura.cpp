#include <bits/stdc++.h>
using namespace std;

int main(){

	cout<<"Ingresar la carga de la unidad de electricidad: ";
	int carga,aux; double total=0.0;
	cin>>carga;
	if(carga>0){  // 50
		if(carga<=50){
			aux=carga;
			carga=0;
		}else{
			aux=50;
			carga-=aux;
		}
		total+=aux*.5;
	}

	if(carga>0){  // 100
		if(carga<=100){
			aux=carga;
			carga=0;
		}else{
			aux=100;
			carga-=aux;
		}
		total+=aux*.75;
	}

	if(carga>0){  // 100
		if(carga<=100){
			aux=carga;
			carga=0;
		}else{
			aux=100;
			carga-=aux;
		}
		total+=aux*1.2;
	}

	if(carga>0){
		total+=carga*1.5;
	}

	total*=1.2; //recargo
	cout<<"El monto final es de "<<total;
	cout<<'\n';

}


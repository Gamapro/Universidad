#include <bits/stdc++.h>
using namespace std;

int x;

int main(){
	while(true){
		cout<<"Caso 1: Cubo de un numero\nCaso 2: Numero par o impar\nCase 3: salir.";	
        cout<<"\nIngrese una opcion: ";
		cin>>x;
		switch(x){
			case 1:
				cout<<"\nIngrese un numero: "; cin>>x;
                cout<<"El cubo de "<<x<<" es: "<<x*x*x<<"\n\n";
				break;	
			case 2:
				cout<<"\nIngrese un numero: "; cin>>x;
                cout<<"El numero "<<x<<" es "<<(x&1?"impar":"par")<<"\n\n";
				break;	
			case 3:
                cout<<"Cerrando programa. Adios :)\n";
                return 0;
				break;	
			default:
				cout<<"Caso invalido. Intente otra vez\n\n";
		}
	}
}

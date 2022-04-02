#include <bits/stdc++.h>
using namespace std;

int x;

int main(){
    cout<<"Su saldo inicial de 1000 Dólares (Solo salida de efectivo).\n";
    int total = 1000,monto,saldoFinal;
	while(true){
        cout<<"Caso 1: Retirar Efectivo\nCaso 2: Ver saldo\nCaso 3: Salir\n";	
        cout<<"Ingrese un numero: ";
        cin>>x;
        switch(x){
			case 1:
                cout<<"Ingrese el monto a retirar: ";
                cin>>monto;
                saldoFinal = total - monto;
                if(saldoFinal>=0){
                    total = saldoFinal;
					cout<<"Monto retirado exitosamente!\n\n";
                }else{
					cout<<"No es posible retirar ese monto. Intente nuevamente.\n\n";
				}
				break;	
			case 2:
                cout<<"Su saldo actual es: "<<total<<"\n\n";
				break;	
			case 3:
                cout<<"Cerrando programa. Adios :)\n";
                return 0;
			default:
				cout<<"Caso invalido. Intente otra vez\n\n";
        }
    }
}

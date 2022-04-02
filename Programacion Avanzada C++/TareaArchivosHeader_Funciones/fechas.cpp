#include "fechas.h"
#include <iostream>
using namespace std;

string s1,s2;
int f1[3],f2[3];
int n,m;
bool f1v=true,f2v=true;
int fact[] = {20, 8 , 2020};

int mayo(string s1, string s2){
    n = s1.size(); m = s2.size();
    for(int i=0, pot = 10, index = 0, val = 0;i<n;i++){
        if(s1[i] == '/'){
            index++;
            val = 0;
        }else{
            val*=pot;
            val+=(int)(s1[i]-'0');
            f1[index] = val;
        }
    }
    for(int i=0, pot = 10, index = 0, val = 0;i<m;i++){
        if(s2[i] == '/'){
            index++;
            val = 0;
        }else{
            val*=pot;
            val+=(int)(s2[i]-'0');
            f2[index] = val;
        }
    }
    
    // Validacion
    if(f1[0]>31 || f1[1] > 12){
        cout<<"Fecha 1 invalida.\n";
        f1v=false;
    }
    if(f2[0]>31 || f2[1] > 12){
        cout<<"Fecha 2 invalida.\n";
        f2v=false;
    }

    if(f1v && !f2v)return 1;
    if(!f1v && f2v)return 2;
    if(!f1v && !f2v)return 0;

    
    if(abs(f1[2])>abs(f2[2])){  // anio 1 cercano
        return 1;
    }else if(abs(f2[2])>abs(f1[2])){  // anio 2 cercano
        return 2;
    }else{   // mismos anios    
        if(abs(f1[1])>abs(f2[1])){  // mes 1 cercano
            return 1;
        }else if(abs(f2[1])>abs(f1[1])){  // mes 2 cercano
            return 2;
        }else{   // mismos meses
            if(abs(f1[0])>abs(f2[0])){  // dia 1 cercano
                return 1;
            }else if(abs(f2[0])>abs(f1[0])){  // dia 2 cercano
                return 2;
            }else{   // misma fecha
                return 3;
            }
       }
    }

    /*//Checar mayor
    if(abs(f1[2]-fact[2])<abs(f2[2]-fact[2])){  // anio 1 cercano
        return 1;
    }else if(abs(f2[2]-fact[2])<abs(f1[2]-fact[2])){  // anio 2 cercano
        return 2;
    }else{   // mismos anios
        
        if(abs(f1[1]-fact[1])<abs(f2[1]-fact[1])){  // mes 1 cercano
            return 1;
        }else if(abs(f2[1]-fact[1])<abs(f1[1]-fact[1])){  // mes 2 cercano
            return 2;
        }else{   // mismos meses
            if(abs(f1[0]-fact[0])<abs(f2[0]-fact[0])){  // dia 1 cercano
                return 1;
            }else if(abs(f2[0]-fact[0])<abs(f1[0]-fact[0])){  // dia 2 cercano
                return 2;
            }else{   // misma fecha
                return 3;
            }
       }
    }
    cout<<"Fecha 1; \n";
    for(int i = 0; i<3; i++){cout<<f1[i]<<" ";}cout<<'\n';
    cout<<"Fecha 2; \n";
    for(int i = 0; i<3; i++){cout<<f2[i]<<" ";}cout<<'\n';*/

}

int main(){
    
    cout<<"Ingrese una fecha con el formato DD/MM/AAAA: "; cin>>s1;
    cout<<"Ingrese una segunda fecha: "; cin>>s2;
    cout<<"Fecha 1: "<<s1<<'\n'<<"Fecha 2: "<<s2<<'\n';
        
    int val = mayo(s1,s2); 
    if(val == 0){
        cout<<"Ninguna de las fechas es valida, intente otra vez.\n";
    }else if(val == 1){
        cout<<"La fecha 1 "<<s1<<" es la mas cercana\n";
    }else if(val == 2){
        cout<<"La fecha 2 "<<s2<<" es la mas cercana\n";
    }else if(val == 3){
        cout<<"Ambas fechas son iguales\n";
    }

    cout<<'\n';

}



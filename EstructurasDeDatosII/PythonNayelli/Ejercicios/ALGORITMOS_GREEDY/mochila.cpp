#include <bits/stdc++.h>
using namespace std;

int capacidad = 6;
int pesos[] = {3,1, 2, 2, 2, 1};
int vals[]  = {2,10, 5, 6, 20, 1}; 
int disponible = capacidad;
int gananciaMax = 0;

int main(){

    cout<<"La idea de mi algoritmo es:\n 1.- Ordenar los valores de ganancia de mayor a menor.";
    cout<<"\n 2.- Recorrer los valores y preguntar:\n";
    cout<<"    - Si aun hay espacio disponible, tomar ese valor.\n";
    cout<<"    - Si no, checar los valores que faltan para tener la maxima ganancia.\n\n";

    cout<<"Capacidad Mochila: "<<capacidad<<'\n';
    int n = sizeof(pesos)/sizeof(int);
    cout<<"Pesos:";
    for(int i=0;i<n;i++) cout<<' '<<pesos[i];
    cout<<'\n';
    cout<<"Valores:";
    for(int i=0;i<n;i++) cout<<' '<<vals[i];
    cout<<'\n';

    // SORT
    for(int i=1;i<n;i++){
        for(int j=i;j>0 && vals[j] > vals[j-1];j--){
            swap(pesos[j-1],pesos[j]);
            swap(vals[j-1],vals[j]);
        }
    }

    cout<<"VALORES ORDENADOS POR IMPORTANCIA\n";
    cout<<"Pesos:";
    for(int i=0;i<n;i++) cout<<' '<<pesos[i];
    cout<<'\n';
    cout<<"Valores:";
    for(int i=0;i<n;i++) cout<<' '<<vals[i];
    cout<<'\n';

    for(int i=0;i<n;i++){
        cout<<'\n'<<"VALOR CHECADO: "<<vals[i]<<" , PESO: "<<pesos[i]<<" , CAPACIDAD DISPONIBLE: "<<disponible<<'\n';
        if(disponible >= pesos[i]){
            gananciaMax+=vals[i];
            disponible-=pesos[i];
            cout<<"Valor tomado\n";
        }else{
            cout<<"Valor omitido\n";
        }
    }
    cout<<"\nLa ganancia maxima fue: "<<gananciaMax<<'\n';
}

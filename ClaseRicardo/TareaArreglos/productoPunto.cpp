#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int n,m;

int main (){
    srand (time(NULL));

    cout<<"Producto punto de matrices cuadradas.\nIngrese la dimension de la primera matriz cuadrada: ";
    cin>>n;
    cout<<"Ingrese la dimension de la segunda matriz cuadrada: ";
    cin>>m;
    int m1[n][n], m2[m][m];
    if(n != m){
        cout<<"Operación fallida. El número de columnas de A es diferente al número de renglones de B.\n";
        return 0;
    }

    cout<<"\nMatriz A\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m1[i][j] = rand()%10;
            cout<<m1[i][j]<<" ";
        }
        cout<<'\n';
    }

    cout<<"\nMatriz B\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            m2[i][j] = rand()%10;
            cout<<m2[i][j]<<" ";
        }
        cout<<'\n';
    }

    int p = 0;
    cout<<"\nProducto Vectorial\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int aux = 0;
            for(int k=0;k<n;k++){ 
                //if(j)cout<<"+ ";
                aux += m1[i][k]*m2[k][j];
            }
            //cout<<"("<<m1[i][j]<<" * "<<m2[j][i]<<") ";
            p+=aux;
            cout<<aux<<" ";
        }
        cout<<'\n';
    }
    cout<<"\nResultado Total = "<<p<<'\n'; 

    return 0;
}

#include <iostream>
using namespace std;

template<class pointer>
#define dbg(x) cout << #x"=" ;

void printPuntero(pointer dir){
    dbg(dir)
    cout<<dir<<'\n';
    cout<<*dir<<'\n';
    cout<<&dir<<'\n';
}

int main(){

/*  int *p, num = 10;
    int **p2, ***p3;
    p = &num;
    p2 = &p;
    p3 = &p2;
    printPuntero(p);
    printPuntero(p2);
    printPuntero(p3)}; */

// Punteros con arreglos
/*  int n, numeros[100], *dir_numeros;
    cout<<"Digite un numero de elementos: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>numeros[i];
    }
    dir_numeros = numeros;
    printPuntero(dir_numeros);
    for(int i=0;i<n;i++){
        cout<<' '<<*(dir_numeros + i);
    }cout<<'\n'; */

// Punteros dobles con matrices
    int **pMatriz;
    int cols, rows;
    cout<<"Ingrese el numero de filas: ";
    cin>>rows;
    cout<<"Ingrese el numero de filas: ";
    cin>>cols;

    pMatriz = new int*[rows];  // New se refiere a apartar la memoria
    for(int i=0;i<rows;i++){
        pMatriz[i] = new int[cols];
    }

    for(int i=0,cont=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            // pMatriz[i][j] = i+j;
            *(*(pMatriz + i) + j) = cont++; //i+j;
            cout<<&pMatriz[i][j]<<"-->"<<pMatriz[i][j]<<"  ";
        }
        cout<<'\n';
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<pMatriz[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<< *(*(pMatriz+i)+j)<<' ';
        }
        cout<<'\n';
    }
}

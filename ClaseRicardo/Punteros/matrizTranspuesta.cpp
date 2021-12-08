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

    int **pMatriz;
    int cols, rows;
    cout<<"Ingrese el numero de filas: ";
    cin>>rows;
    cout<<"Ingrese el numero de filas: ";
    cin>>cols;

    /// Crear Matriz
    pMatriz = new int*[rows];  // New se refiere a apartar la memoria
    for(int i=0;i<rows;i++){
        pMatriz[i] = new int[cols];
    }

    cout<<"Ingrese los valores: ";
    for(int i=0,x=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            // pMatriz[i][j] = i+j;
            cin>>x;
            *(*(pMatriz + i) + j) = x; //i+j;
            // cout<<&pMatriz[i][j]<<"-->"<<pMatriz[i][j]<<"  ";
        }
    }

    cout<<"La matriz es\n";    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            // cout<<pMatriz[i][j]<<' ';
            cout<< *(*(pMatriz+i)+j)<<' ';
        }
        cout<<'\n';
    }

    int **pMatrizTransupuesta;
    pMatrizTransupuesta = new int*[cols]; 
    for(int i=0;i<cols;i++){
        pMatrizTransupuesta[i] = new int[rows];
    }

    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            *(*(pMatrizTransupuesta + i) + j) = *(*( pMatriz + j) + i);
        }
    }

    cout<<"La matriz Transpuesta es\n";    
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            cout<< *(*(pMatrizTransupuesta+i)+j)<<' ';
        }
        cout<<'\n';
    }
}


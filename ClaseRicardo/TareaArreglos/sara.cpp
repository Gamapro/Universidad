#include<iostream>
using namespace std;

int matriz1[40][40];
int filas_uno,columnas_uno;
bool mat1;

int matriz2[40][40];
int filas_dos,columnas_dos;
bool mat2;

int res[40][40];

void datos();
void simetria(int matriz1[][40],int matriz2[][40],int,int,int,int);
void multiplicar(int matriz1[][40],int matriz2[][40],int,int,int,int);


/*
void simetria(int matriz1[][40], int matriz2[][40],int filas_uno, int columnas_uno, int filas_dos, int columnas_dos){
   int uno;
    if(filas_uno==columnas_uno){                 //simetría matriz 1
        mat1=true;
    }
 
    int dos;
    if(filas_dos==columnas_dos){          //simetría matriz 2
        mat2=true;
    }
}
*/

void simetria(int matriz1[][40], int matriz2[][40],int filas_uno, int columnas_uno, int filas_dos, int columnas_dos){
   int uno=0;
    if(filas_uno==columnas_uno){                 //simetría matriz 1
     for(int i=0;i<filas_uno;i++){
        for(int j=0;j<columnas_uno;j++){
            if(matriz1[i][j]==matriz1[j][i]){
                uno++;
            }
        }
      }
      if(uno==filas_uno*columnas_uno){
        mat1=true;
      }
    }
 
    int dos=0;
    if(filas_dos==columnas_dos){          //simetría matriz 2
     for(int i=0;i<filas_dos;i++){
        for(int j=0;j<columnas_dos;j++){
            if(matriz2[i][j]==matriz2[j][i]){
               dos++;
            }
        }
      }
      if(dos==filas_dos*columnas_dos){
        mat2=true;
      }
    }
}


void datos(){
    cout<<"numero de filas de la matriz 1: "; cin>>filas_uno;
    cout<<"numero de columnas de la matriz 1: ";cin>>columnas_uno;
  
    for(int i=0;i<filas_uno;i++){
        for(int j=0; j<columnas_uno;j++){
            cout<<"Numero: ["<<i<<"]["<<j<<"]: "; 
            cin>>matriz1[i][j];
        }
    } 

    cout<<"numero de filas de la matriz 2: "; cin>>filas_dos;
    cout<<"numero de columnas de la matriz 2: "; cin>>columnas_dos;

    for(int i=0;i<filas_dos;i++){
        for(int j=0; j<columnas_dos;j++){
            cout<<"Numero: ["<<i<<"]["<<j<<"]: "; 
            cin>>matriz2[i][j];
        }
    } 
}

void multiplicar(int matriz1[][40], int matriz2[][40],int filas_uno, int columnas_uno, int filas_dos, int columnas_dos){
 if(columnas_uno==filas_dos){
   for(int i=0;i<filas_uno;i++){
       for(int j=0;j<columnas_dos;j++){
          for(int k=0;k<columnas_uno;k++){
             res[i][j] += matriz1[i][k] * matriz2[k][j];
          }
          cout<<res[i][j]<<" ";
          
        }
          cout<<'\n';
   }
 }
}

int main(){
    datos();
    simetria(matriz1, matriz2 , filas_uno, columnas_uno, filas_dos, columnas_dos);
   if(mat2==true && mat1==true){
       multiplicar(matriz1, matriz2 , filas_uno, columnas_uno, filas_dos, columnas_dos);
    }

return 0;
}

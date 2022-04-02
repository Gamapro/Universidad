#include "Rectangulo.h"
#include <time.h>

int main(){
    srand (time(NULL));
    Rectangulo *arr[10];
    for(int i=0;i<10;i++){
        arr[i] = new Rectangulo(float(rand()%10),float(rand()%10));
        arr[i]->datos();
        arr[i]->perimetro();
        arr[i]->area();
    }
}   

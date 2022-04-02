#include <iostream>
#include <cstring>
//#include <stdlib.h>
using namespace std;

int n;
char s[10000];

int main (){

    int index;
    cout<<"Ingrese un numero: ";
    cin>>s;
    n = strlen(s);

    for(index=n-1;index>=0;index--){
        if(s[index] == '9'){
            s[index] = '0'; 
        }else{
            s[index]++;
            break;
        }
    }
    if(index == -1){
        s[n] = '0'; 
        s[0] = '1';
    }

    cout<<"El numero final es: "<<s<<'\n'; 
    cout<<'\n';

    return 0;
}


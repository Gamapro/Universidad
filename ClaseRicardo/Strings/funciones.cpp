#include <iostream>
#include <string.h>

using namespace std;

int main(){

    char word1[100],word2[100];
    cout<<"Digite una palabra: ";
    cin.getline(word1,100,'\n');
    cout<<"Digite otra palabra: ";
    cin.getline(word2,100,'\n');
    cout<<"Tamaño cadena 1: "<<strlen(word1)<<'\n';
    cout<<"Tamaño cadena 2: "<<strlen(word2)<<'\n';

    int comp = strcmp(word1,word2);
    if(comp == 0){
        cout<<"Las cadenas son iguales.\n";
    }else if(comp > 0){
       cout<<"La cadena 2 es mayor a la cadena 1.\n";
    }else{
       cout<<"La cadena 1 es mayor a la cadena 2.\n";
    }

   const char s[2] = " ";
   char *token;
   token = strtok(word1, s);
   /* walk through other tokens */
   while( token != NULL ) {
        //cout<<s<<'\n';
        printf( " %s\n", token );
        token = strtok(NULL,s);
   }

}

#include <bits/stdc++.h>

using namespace std;

int chars[256];

int checa(string s){

    int n = s.size();
    for(int i=0;i<n;i++){
        chars[(int)s[i]]++;
    }

    for(int i=0;i<n;i++){
        if(chars[(int)s[i]] == 1)return i;
    }

    return -1;
}

int main(){

    cout<<"Ingrese una cadena: ";    
    string s;
    getline(cin,s);
    int val = checa(s);
    if(val == -1){
        cout<<"Todos los caracteres se repiten almenos una vez"<<'\n';
        return 0;
    }
    cout<<"Primer caracter no repetido encontrado en el indice: "<<val<<'\n';

}


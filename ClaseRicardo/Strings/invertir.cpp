#include <bits/stdc++.h>

using namespace std;

string invertir(string s){
    int n = s.size();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
    return s;
}

int main(){

    cout<<"Ingrese una cadena: ";    
    string s;
    getline(cin,s);
    cout<<"String invertido: "<<invertir(s)<<'\n';

}

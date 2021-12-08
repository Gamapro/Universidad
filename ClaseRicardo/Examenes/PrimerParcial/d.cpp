#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int target,n;

string split(string s, char coso){
    int n=s.size();
    string res = "";
    string aux = "";
    for(int i=0;i<n;i++){
        if(s[i] == coso){
            if(aux != ""){ 
                reverse(aux.begin(),aux.end());
                res+=aux+" ";
            }
            aux = "";
        }else{
            aux+=s[i];
        }
    }
    if(aux != ""){ 
        reverse(aux.begin(),aux.end());
        res+=aux+" ";
    }
    return res;
}

int main(){
    cout<<"Ingrese el texto a voltear.\n";
    string s;
    //cin.ignore();
    getline(cin,s);
    cout<<"Tu cadena es: "<<s<<'\n';
    s = split(s,' ');
    cout<<"Tu cadena volteada es: "<<s<<'\n';

}


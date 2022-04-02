#include <bits/stdc++.h>
using namespace std;

int n,a,b,c;
vector<string> arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
set<string> p;
string s;

int main(){

    cout<<"Ingrese el numero de palabras: "; cin>>n;
    
    cout<<"Ingrese las palabras: ";
    for(int i=0;i<n;i++){
        cin>>s;
        string aux = "";
        for(char c : s){
            c = tolower(c);
            aux+=arr[(int)c-'a'];
        }
        p.insert(aux);
    }
    
    

    cout<<p.size();
    cout<<'\n';

}

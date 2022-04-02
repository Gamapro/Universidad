#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void escribir();

vector<string> split(string s, char coso){
    int n=s.size();
    vector<string> v;
    string aux = "";
    for(int i=0;i<n;i++){
        if(s[i] == coso){
            if(aux != ""){ 
                v.push_back(aux);
            }
            aux = "";
        }else{
            aux+=s[i];
        }
    }
    if(aux != ""){ 
        v.push_back(aux);
    }
    return v;
}



int main(){
    
     escribir();

}

void escribir(){
 
    ifstream f1,f2;
    ofstream f3;
    string n1,n2,s1,s2;
    string salida = "salida.txt";

    cout<<"Digite el nombre del primer archivo: ";
    getline(cin,n1);
    f1.open(n1,ios::in);

    if(f1.fail()){  // Funcion que regresa un booleano, si el archivo pudo o no abrirse 
        cout<<"Error al abrir el primer archivo.\n";       
        f1.close();
        return;
    }

    cout<<"Digite el nombre del segundo archivo: ";
    getline(cin,n2);
    f2.open(n2,ios::in);

    if(f2.fail()){  // Funcion que regresa un booleano, si el archivo pudo o no abrirse 
        cout<<"Error al abrir el segundo archivo.\n";       
        f1.close();
        f2.close();
        return;
    }

    f3.open(salida,ios::out);

    vector<string> v;
    while(!f1.eof() || !f2.eof()){
        if(!f1.eof() && !f2.eof()){
            getline(f1,s1);
            getline(f2,s2);
            s1=s1+":"+s2;
            v = split(s1,':');
        }else if(!f1.eof()){
            getline(f1,s1);
            v = split(s1,':');
        }else if(!f2.eof()){
            getline(f2,s1);
            v = split(s1,':');
        }

        sort(v.begin(),v.end());
        bool ya=false;
            s1 = "";
        for(int i=0;i<v.size();i++){
            if(i+1 < v.size() && v[i+1] == v[i]){
                while(i+1 < v.size() && v[i+1] == v[i]) i++;
                if(i == v.size()-1 && i-1 > 0 && v[i-1] == v[i])i++;
            }else{
                if(ya)s1+=":";
                ya = true;
                s1+=v[i];
            }
        }
        f3<<s1<<'\n';
    }

    f1.close();
    f2.close();
    f3.close();

}

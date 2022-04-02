#include <bits/stdc++.h>

using namespace std;

int checkSubstring(string str1, string str2){
    int index, pos = 0;
    return (int)(((index = str1.find(str2, pos)) != string::npos));
}

int main(){

    int n;
    cout<<"Ingrese el numero de cadenas: ";
    cin>>n;
    cin.ignore();
    string s[n];
    for(int i=0;i<n;i++){    
        cout<<"Ingrese una cadena: ";
        getline(cin,s[i]);
    }

    cout<<"Subcadenas:";
    for(int i=0;i<n;i++){
        int jala=0;
        for(int j=0;j<n;j++){
            if(i!=j)jala = max(jala,checkSubstring(s[j],s[i]));
        }
        if(jala)cout<<' '<<s[i];
    }
    cout<<'\n';
    
}


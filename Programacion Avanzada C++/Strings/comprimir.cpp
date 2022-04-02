#include <bits/stdc++.h>

using namespace std;

/*string comprimir(string s){
    int n = s.size();
    string s2 = "";
    sort(s.begin(),s.end());
    char c;
    for(int i=0,j=0;i<n;i=j+1){
        c = s[i];
        for(j=i;j+1<n&&s[j+1]==s[i];j++){}
        int cant = j-i+1;
        s2+=c;
        if(cant > 1){
            string s3 = "";
            while(cant>0){
                s3+=(char)(cant%10)+'0';
                cant/= 10;
            }
            reverse(s3.begin(),s3.end());
            s2+=s3;
        }
    }
    return s2;
}*/

string comprimir(string s){
    int n = s.size(),i=0,voy=0,iba=0,j=0;
    sort(s.begin(),s.end());
    for(i=0,voy=0,iba=0,j=0;i<n;i=j+1, voy++){
        s[voy] = s[i];
        iba = voy;
        for(j=i;j+1<n&&s[j+1]==s[i];j++){}
        int cant = j-i+1;
        if(cant > 1){
            while(cant>0){
                s[++voy]=(char)(cant%10)+'0';
                cant/= 10;
            }
            //cout<<"J: "<<j<<", Iba: "<<iba+1<<", Voy: "<<voy<<'\n';
            reverse(s.begin()+ iba +1,s.begin()+voy+1);
        }
    }
    s = s.substr(0,voy);
    return s;
}

int main(){

    cout<<"Ingrese una cadena a comprimir: ";    
    string s;
    getline(cin,s);
    s = comprimir(s);
    cout<<"String comprimido: "<<s<<'\n';

}


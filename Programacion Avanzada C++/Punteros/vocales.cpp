#include <iostream>
using namespace std;

const int maxn = 10000;

int main(){
    
    char * vocales = "aeiou";
    int *arr = new int[5];
    char *s = new char[maxn];
    cin.getline(s,maxn,'\n');
    int n; //= strlen(s);
    for(int i = 0; *(s+i) != '\0'; i++, n++){
        //cout<<*(s+i);
        char c = tolower(*(s+i));
        for(int j=0;j<5;j++){
            if(c == *(vocales + j)){
                *(arr+j)+=1;
            }
        }
    }
    for(int j=0;j<5;j++){
        cout<<*(vocales+j)<<": "<<*(arr+j)<<'\n';
    }
    cout<<'\n';
}

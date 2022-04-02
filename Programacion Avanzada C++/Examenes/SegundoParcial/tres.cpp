#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a,b;
const int maxn = 1e6 + 6;
bool criba[maxn];
set<int> p;

ll countBits(int x){
    int ans=0;

    while(x){
        ans+=int(x&1);
        x>>=1;
    }

    return ans;
}

int main(){

    cout<<"Ingrese el numero L: "; cin>>a;
    cout<<"Ingrese el numero R: "; cin>>b;
    
    criba[0]=criba[1]=true;   
    for(ll i=2;i*i<maxn;i++){
        if(!criba[i]){
            for(ll j = i*i;j<maxn;j+=i){
                criba[j] = true;
            }
        }
    }
    for(ll i=2;i<maxn;i++){
        if(!criba[i])
        p.insert(i);
    }
    
    ll cont=0;
    for(int x=a;x<=b;x++){
        int c = countBits(x);
        if(!criba[c])cont++;
    }
    cout<<cont;

    cout<<'\n';
}

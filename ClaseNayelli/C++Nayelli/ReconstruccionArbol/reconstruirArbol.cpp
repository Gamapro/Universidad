#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reconstruir(vector<char> &dfs, vector<char> &orden, vector<vector<string> > &adj, int izqDFS, int derDFS, int izqORDEN, int derORDEN){
    
    char root = dfs[izqDFS];
    cout<<"Root: "<<root<<", IzqDFS: "<<izqDFS<<", DerDFS: "<<derDFS<<", IzqORDEN: "<<izqORDEN<<", DerORDEN: "<<derORDEN<<'\n';
    if(izqDFS >= derDFS || izqORDEN >= derORDEN ) return;  // Nodo sin hijos

    int i;
    for(i=izqORDEN;i<=derORDEN && dfs[izqDFS] != orden[i];i++);
    
    cout<<"I: "<<i<<'\n';

    string s;
    if(i == izqORDEN){ // No hay izquierda
        // Derecha
        s = "Der: "; s+=dfs[i+izqDFS-izqORDEN+1];
        adj[root-'A'].emplace_back(s);
        cout<<"Root "<<root<<" manda a derecha "<<dfs[i+izqDFS-izqORDEN+1]<<'\n';
        reconstruir(dfs,orden,adj,i+izqDFS-izqORDEN+1,derDFS,i+1,derORDEN);

    }else if( i == derORDEN){ // No hay derecha
        // Izquierda
        s = "Izq: "; s+=dfs[izqDFS+1];
        adj[root-'A'].emplace_back(s);
        cout<<"Root "<<root<<" manda a izquierda "<<dfs[izqDFS+1]<<'\n';
        reconstruir(dfs,orden,adj,izqDFS+1,i+izqDFS-izqORDEN,izqORDEN,i-1);

    }else{  // Hay ambos

        // Izquierda
        s = "Izq: "; s+=dfs[izqDFS+1];
        adj[root-'A'].emplace_back(s);
        cout<<"Root "<<root<<" manda a izquierda "<<dfs[izqDFS+1]<<'\n';
        reconstruir(dfs,orden,adj,izqDFS+1,i+izqDFS-izqORDEN,izqORDEN,i-1);
        

        // Derecha
        s = "Der: "; s+=dfs[i+izqDFS-izqORDEN+1];
        adj[root-'A'].emplace_back(s);
        cout<<"Root "<<root<<" manda a derecha "<<dfs[i+izqDFS-izqORDEN+1]<<'\n';
        reconstruir(dfs,orden,adj,i+izqDFS-izqORDEN+1,derDFS,i+1,derORDEN);

    }

    return;

}

void imp(vector<vector<string> > &adj){
    
    int n=adj.size();
    for(int i=0;i<n;i++){
        cout<<char('A'+i)<<": ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<"   ";
        }
        cout<<'\n';
    }

}

void solve(){    
    int n;
    cout<<"Ingrese el numero de nodos del arbol: ";
    cin>>n;
    vector<char> dfs(n),orden(n);
    cout<<"Ingrese el DFS del arbol: ";
    for(int i=0;i<n;i++){
        cin>>dfs[i];
    }
    cout<<"Ingrese el EN-ORDEN del arbol: ";
    for(int i=0;i<n;i++){
        cin>>orden[i];
    }

    vector<vector<string> > adj(n);

    reconstruir(dfs,orden,adj,0,n-1,0,n-1);
    
    cout<<"ROOT: "<<dfs[0]<<'\n';
    imp(adj);

}



int main(){
    solve();
}

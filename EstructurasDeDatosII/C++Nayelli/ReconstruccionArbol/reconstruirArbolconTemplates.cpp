#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class TreeReconstructor{
public:
    

    TreeReconstructor(){}

    void reconstruir(vector<T> &dfs, vector<T> &orden, map<T,vector<string> > &adj, int izqDFS, int derDFS, int izqORDEN, int derORDEN){

        T root = dfs[izqDFS];
        //cout<<"Root: "<<root<<", IzqDFS: "<<izqDFS<<", DerDFS: "<<derDFS<<", IzqORDEN: "<<izqORDEN<<", DerORDEN: "<<derORDEN<<'\n';
        if(izqDFS >= derDFS || izqORDEN >= derORDEN ){ adj[root].clear(); return; } // Nodo sin hijos

        int i;
        for(i=izqORDEN;i<=derORDEN && dfs[izqDFS] != orden[i];i++);
        
        //cout<<"I: "<<i<<'\n';

        string s,s2;
        stringstream ss;
        if(i == izqORDEN){ // No hay izquierda
            // Derecha
            s = "Der: "; 
            ss.clear();
            ss<<dfs[i+izqDFS-izqORDEN+1];
            ss>>s2;
            s+=s2;
            adj[root].emplace_back(s);
            //cout<<"Root "<<root<<" manda a derecha "<<dfs[i+izqDFS-izqORDEN+1]<<'\n';
            reconstruir(dfs,orden,adj,i+izqDFS-izqORDEN+1,derDFS,i+1,derORDEN);

        }else if( i == derORDEN){ // No hay derecha
            // Izquierda
            s = "Izq: "; 
            ss.clear();
            ss<<dfs[izqDFS+1];
            ss>>s2;
            s+=s2;
            adj[root].emplace_back(s);
            //cout<<"Root "<<root<<" manda a izquierda "<<dfs[izqDFS+1]<<'\n';
            reconstruir(dfs,orden,adj,izqDFS+1,i+izqDFS-izqORDEN,izqORDEN,i-1);

        }else{  // Hay ambos

            // Izquierda
            s = "Izq: "; 
            ss.clear();
            ss<<dfs[izqDFS+1];
            ss>>s2;
            s+=s2;
            adj[root].emplace_back(s);
            //cout<<"Root "<<root<<" manda a izquierda "<<dfs[izqDFS+1]<<'\n';
            reconstruir(dfs,orden,adj,izqDFS+1,i+izqDFS-izqORDEN,izqORDEN,i-1);
            

            // Derecha
            s = "Der: "; 
            ss.clear();
            ss<<dfs[i+izqDFS-izqORDEN+1];
            ss>>s2;
            s+=s2;
            adj[root].emplace_back(s);
            //cout<<"Root "<<root<<" manda a derecha "<<dfs[i+izqDFS-izqORDEN+1]<<'\n';
            reconstruir(dfs,orden,adj,i+izqDFS-izqORDEN+1,derDFS,i+1,derORDEN);

        }

        return;

    }

    void imp(map<T,vector<string> > &adj){
        for(auto &par : adj){
            //cout<<char('A'+i)<<": ";
            cout<<par.first<<": ";
            for(int j=0;j<par.second.size();j++){
                cout<<par.second[j]<<"   ";
            }
            cout<<'\n';
        }

    }

    void show(vector<T> &dfs, vector<T> &orden){
        cout<<"DFS: ";
        for(int i=0;i<int(dfs.size());i++){
            cout<<dfs[i]<<' ';
        }
        cout<<"\nINORDER: ";
        for(int i=0;i<int(orden.size());i++){
            cout<<orden[i]<<' ';
        }cout<<'\n';

    }

    void solve(){    
        int n;
        cout<<"Ingrese el numero de nodos del arbol: ";
        cin>>n;
    
        vector<T> dfs, orden;
        map<T,vector<string> > adj;
    
        dfs.clear(); dfs.resize(n);
        orden.clear(); orden.resize(n);
        adj.clear(); 

        cout<<"Ingrese el DFS del arbol: ";
        for(int i=0;i<n;i++){
            cin>>dfs[i];
        }
        cout<<"Ingrese el EN-ORDEN del arbol: ";
        for(int i=0;i<n;i++){
            cin>>orden[i];
        }

        reconstruir(dfs,orden,adj,0,n-1,0,n-1);
        show(dfs, orden);
        cout<<"ROOT: "<<dfs[0]<<'\n';
        imp(adj);
    }

};

int main(){

    
    /*
        Use templates para poder ingresar indices con cadenas, chars, ints, etc
        Tambien usa map para poder almacenar bien los datos sin importar el tipo
        de valo dell template
        SI se quiere usar un struct o clase, debe de implementarse el operador <
        para que el map funcione adecuadamente, o sustituirlo por unordered_map
    
        La representacion final se muestra en forma de lista de adyacencia

        Estan comentados cout en el metodo reconstruir
        Estos cout muestran paso a paso recursivamente en que orden se estan visitando los nodos
        y como estan siendo modificados los indices

    */

    /*
    Ejemplo 1
    9
    5 2 1 4 3 8 7 6 9
    1 2 3 4 5 6 7 8 9

    Final:

                 5
                / \
               /   \
              2     8
             / \   / \
            1   4 7   9
               / /   
              3 6      
                     
                    

    */
    TreeReconstructor<int> t;
    t.solve();


    /*
    Ejemplo 2
    9
    A B D E C F G H I
    D E B A F C G I H

    Final:

                A
               / \
              B   C
             /   / \
            D   F   G
             \       \
              E       H
                     /
                    I

    */
    TreeReconstructor<char> t2;
    t2.solve();

}

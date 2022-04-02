#include <iostream>
#include <vector>
using namespace std;

void cap(vector<int> vec){
    cout<<"Size: "<<vec.size()<<'\n';
    cout<<"Capacity: "<<vec.capacity()<<'\n';
    return;
}
void cap(int a, int b){
    cout<<"Size: "<<a<<'\n';
    cout<<"Capacity: "<<b<<'\n';
    return;
}

int main(){

    // Vector constructor
    vector<int> vec(0);
    cap(vec);

    // Size - Size actual
    // Capacity - Capacidad reservada
    // Max_size - Tamaño maximo posible

    int capa = vec.capacity(); 
    for(int i=0;i<100;i++){
        vec.push_back(5);
        if(capa != vec.capacity()){
            capa = vec.capacity();
            cap(vec.size(),capa);
        }
    }
    cap(vec);

/*    capa = vec.capacity();
    while(!vec.empty()){
        vec.pop_back();
        if(capa != vec.capacity()){
            capa = vec.capacity();
            cap(vec.size(),capa);
        }
        
    }
    cap(vec);
    cout<<vec.capacity(); */


    int n=3,m=5;
    vector< vector<int> > adj(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            adj[i][j] = i+j;
            cout<<adj[i][j]<<' ';
        }
        cout<<'\n';
    }
    


    cout<<'\n';
}

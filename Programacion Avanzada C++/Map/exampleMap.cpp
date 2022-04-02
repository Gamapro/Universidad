#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    
    map<string,int> mapa;

    mapa["Juanito"] = 20;
    //mapa.insert(mapa.find("Gama"),{"Gama",89});
    mapa["Gama"] = 18;
    mapa["Arubaito"] = 40;

    mapa.emplace("Gama",89);
    mapa.insert({"Fer",99});
    mapa.insert({"Fer",991});

    for(map<string,int>::iterator it = mapa.begin(); it!= mapa.end() ; ++it){
        cout<<it->first<<' '<<it->second<<'\n';
    } cout<<'\n';

    

}

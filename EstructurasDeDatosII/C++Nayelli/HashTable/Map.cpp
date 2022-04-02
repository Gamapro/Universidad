#include<bits/stdc++.h>
#include <typeinfo>
using namespace std;

template <class K, class V>
class Map{
public:

    int mod = 13, pot = 26;
    vector< vector< pair<K,V> > > table;

    Map(){
        this->mod = 13;
        this->pot = 26;
        table.assign(this->mod, vector< pair<K,V> >());
    }

    Map(int tam, int pote){
        this->mod = tam;
        this->pot = pote;
        table.assign(13, vector< pair<K,V> >());
    }


    ~Map(){
        cout<<"~Map\n";
        table.clear();
        return;
    }

    
    friend ostream& operator<< (ostream& os, const Map& m) {
        for(int i=0;i<m.mod;i++){
            os<<"Index: ";
            if(i < 10) os<<' ';
            os<<i<<" - [";
            for(int j=0;j<(int)m.table[i].size();j++){
                if(j) os<<' ';
                os<<"(K:"<<m.table[i][j].first<<", V:"<<m.table[i][j].second<<")";
            }
            os<<']'<<'\n';
        }
        return os;
    }

    void insert(K key, V value){
        if(contains(key)) return;
        int hashValue = calcHash(key);
        this->table[hashValue].emplace_back(key,value);
        return;
    }


    bool contains(K key){
        int hashValue = calcHash(key);
        for(int i=0;i<table[hashValue].size(); i++){
            if(table[hashValue][i].first == key) return true;
        }
        return false;
    }


    void remove(K key){
        int hashValue = calcHash(key);
        for(int i=0;i<table[hashValue].size(); i++){
            if(table[hashValue][i].first == key){
                table[hashValue].erase(table[hashValue].begin()+i);
                return;
            }
        }
        return;
    }


    V get(K key){
        int hashValue = calcHash(key);
        for(int i=0;i<table[hashValue].size(); i++){
            if(table[hashValue][i].first == key) return table[hashValue][i].second;
        }
        return (V)NULL;
    }

    int calcStringHash(K s){
        int val = 0, pot = 1;
        for(int i=0;i<(int)s.size(); i++){
            val = (val + (int(s[i]) * pot )) % this->mod;
            pot = (pot * this->pot) % this->mod;
        }
        return val;
    }


    int calcHash(int data){
        int hashValue = 0;
        if(typeid(K) == typeid(int)){
            // cout<<"int\n";
            hashValue = data % this->mod;
        }
        return hashValue;
    }

    int calcHash(string data){
        int hashValue = 0;
        if(typeid(K) == typeid(string)){
            // cout<<"string\n";
            int val = 0, pot = 1;
            for(int i=0;i<(int)data.size(); i++){
                val = (val + (int(data[i]) * pot )) % this->mod;
                pot = (pot * this->pot) % this->mod;
            }
            hashValue = val;
        }
        return hashValue;
    }


    void printType(){
        if(typeid(K) == typeid(string)){
            cout<<"string\n";
        }else if(typeid(K) == typeid(int)){
            cout<<"int\n";
        }
    }


};


int main(){

    Map<int,double> m1;
    Map<int,char> m2;
    Map<int,int> m3;
    Map<int,string> m4;
    Map<string,double> m5;
    Map<string,char> m6;
    Map<string,int> m7;
    Map<string,string> m8;

/*
    m3.insert(1,1);
    m3.insert(2,2);
    m3.insert(3,3);
    m3.insert(4,4);
    m3.insert(4,4);
    m3.insert(4,4);
    m3.insert(4,5);
    m3.insert(17,4);
    cout<<m3.get(4)<<'\n';
    cout<<m3.get(1)<<'\n';
    cout<<m3.get(20)<<'\n';
    cout<<m3.contains(20)<<'\n';
    cout<<m3.contains(1)<<'\n';
    cout<<m3.contains(2)<<'\n';
    cout<<m3<<'\n';   
    m3.remove(1);
    m3.remove(1);
    m3.remove(1);
    m3.remove(2);
    m3.remove(4);
    m3.remove(123112);
    cout<<m3<<'\n';*/ 


    m7.insert(string("hola"),20);
    m7.insert(string("adios"),1);
    m7.insert(string("a"),1);
    m7.insert(string("a"),2);
    m7.insert(string("a"),2);
    m7.insert(string("b"),1);
    m7.insert(string("c"),1);
    cout<<m7.get(string("hola"))<<'\n';
    cout<<m7.get(string("a"))<<'\n';
    cout<<m7.get(string("noesta"))<<'\n';
    cout<<m7.contains(string("hola"))<<'\n';
    cout<<m7.contains(string("a"))<<'\n';
    cout<<m7.contains(string("noesta"))<<'\n';
    cout<<m7<<'\n';
    m7.remove(string("hola"));
    m7.remove(string("hola"));
    m7.remove(string("hola"));
    cout<<m7<<'\n';
}

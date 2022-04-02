#include<bits/stdc++.h>
#include <typeinfo>
using namespace std;

template <class T>
class Set{
public:

    int mod = 13, pot = 26;
    vector< vector<T> > table;

    Set(){
        this->mod = 13;
        this->pot = 26;
        table.assign(this->mod, vector<T>());
    }

    Set(int tam, int pote){
        this->mod = tam;
        this->pot = pote;
        table.assign(13, vector<T>());
    }


    ~Set(){
        cout<<"~Set\n";
        table.clear();
        return;
    }


    friend ostream& operator<< (ostream& os, const Set& s) {
        for(int i=0;i<s.mod;i++){
            os<<"Index: ";
            if(i < 10) os<<' ';
            os<<i<<" - [";
            for(int j=0;j<(int)s.table[i].size();j++){
                if(j) os<<' ';
                os<<s.table[i][j];
            }
            os<<']'<<'\n';
        }
        return os;
    }

    void insert(T key){
        if(contains(key)) return;
        int hashValue = calcHash(key);
        this->table[hashValue].emplace_back(key);
        return;
    }


    bool contains(T key){
        int hashValue = calcHash(key);
        return (find(table[hashValue].begin(), table[hashValue].end(), key) != table[hashValue].end());
    }


    void remove(T key){
        int hashValue = calcHash(key);
        auto position = find(table[hashValue].begin(), table[hashValue].end(), key);
        if(position != table[hashValue].end()){
            table[hashValue].erase(position);
        }
        return;
    }


    int calcStringHash(T s){
        int val = 0, pot = 1;
        for(int i=0;i<(int)s.size(); i++){
            val = (val + (int(s[i]) * pot )) % this->mod;
            pot = (pot * this->pot) % this->mod;
        }
        return val;
    }


    int calcHash(int data){
        int hashValue = 0;
        if(typeid(T) == typeid(int)){
            // cout<<"int\n";
            hashValue = data % this->mod;
        }
        return hashValue;
    }

    int calcHash(string data){
        int hashValue = 0;
        if(typeid(T) == typeid(string)){
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
        if(typeid(T) == typeid(string)){
            cout<<"string\n";
        }else if(typeid(T) == typeid(int)){
            cout<<"int\n";
        }
    }


};


int main(){
   
   Set<int> s;
   Set<string> s2;
/*
// Int insert
    s.insert(0);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    s.insert(123);
    s.insert(123);
    s.insert(123);
    s.insert(123);
    s.insert(1234);
    cout<<s;
    cout<<s.contains(0)<<'\n';
    cout<<s.contains(7)<<'\n';
    cout<<s.contains(10)<<'\n';
    s.remove(123);
    s.remove(123);
    s.remove(123);
    s.remove(10);
    cout<<s<<'\n';
*/

/*
// String insert
    string str = "hola";
    s2.insert(str);
    s2.insert(string("adios"));
    s2.insert(string("hola"));
    s2.insert(string("a"));
    s2.insert(string("a"));
    s2.insert(string("a"));
    s2.insert(string("a"));
    s2.insert(string("a"));
    s2.insert(string("a"));
    s2.insert(string("b"));
    s2.insert(string("c"));
    s2.insert(string("d"));
    s2.insert(string("eios"));
    s2.insert(string("ios"));
    cout<<s2<<'\n'; 
   
    cout<<s2.contains(string("hola"))<<'\n'; 
    cout<<s2.contains(string("noesta"))<<'\n'; 
    cout<<s2.contains(string("tampoco"))<<'\n'; 
    s2.remove(string("diez"));
    s2.remove(string("hola"));
    s2.remove(string("como"));
    
    cout<<s2;*/ 

}

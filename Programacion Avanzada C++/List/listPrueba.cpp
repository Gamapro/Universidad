#include <iostream>
#include <list>
using namespace std;


int main(){
    
    list<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.push_front(4);
    v.push_front(5);
    v.push_front(6);

    for(list<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<'\n';

    list<int>::iterator it = v.begin();
    it++;
    v.insert(it,21);
    for(list<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<'\n';
    

    list<int>::iterator erase_it = v.end();
    erase_it++;
    v.erase(erase_it);
    for(list<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<'\n';

}

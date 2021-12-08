#include <bits/stdc++.h>
using namespace std;

int n,a,b,c;
vector<int> v;

class Node{
public:

    Node* next;
    int data;
    
    Node(){ next = nullptr; data = 0; }

    Node(int data){ 
        next = nullptr; 
        this->data = data;
    }

};

class Lista{
public:
    
    Node* head;

    Lista(){ head = nullptr; }

    Lista(Node* aux){
        head = aux;
    }

    void insert(int data){
        Node* n = new Node(data);
        if(head == nullptr){
            head = n;
        }else{
            Node* aux = head;
            while(aux->next != nullptr){
                aux = aux->next;
            }
            aux->next = n;
        }
    }

    void print(){
        cout<<"[";
        Node* aux = head;
        while(aux != nullptr){
            cout<<aux->data<<' ';
            aux = aux->next;
        }
        cout<<"]\n";
        return;
    }

    int listToDecimalValue(){
        int ans = 0;
        Node* aux = head;
        while(aux != nullptr){
            ans<<=1;
            ans+=aux->data;
            aux = aux->next;
        }
        return ans;
    }

};

int main(){

    Lista lis;
    cout<<"Ingrese el numero de elementos: "; cin>>n;
    
    cout<<"Ingrese los elementos: ";
    for(int i=0;i<n;i++){
        cin>>a;
        lis.insert(a);
    }
    lis.print();
    cout<<lis.listToDecimalValue()<<'\n';

}

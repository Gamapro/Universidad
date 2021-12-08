#include <iostream>
using namespace std;

template<class T>
class Stack{
public:
    
    class Node{
    public:
        Node *next;
        T data;

        Node(){ this->next = nullptr; }

        Node(T data){
            next = nullptr;
            this->data = data;
        }

        ~Node(){
            cout<<"  ~Node("<<data<<")"<<endl;
        }

        friend ostream& operator<<(ostream& output,const Node& n){
            output<< n.data ;
            return output;
        }

    };

    Node *first;

    Stack(){ first = nullptr; }

    ~Stack(){  
        Node* n = this->first;
        while(n != nullptr){
            Node* aux = n;
            n = n->next;
            delete aux;
        }
        cout<<"~Stack Delete\n";
    }

    void push(T data){
        Node* n = new Node(data);
        n->next = this->first;
        this->first = n;
        return;
    }

    T pop(){
        if(this->first == nullptr){
            return (T)NULL;
        }
        Node* aux = this->first;
        this->first = this->first->next;
        T cosa = aux->data;
        delete aux;
        return cosa;
    }

    T top(){
        return this->first == nullptr ? (T)NULL : this->first->data;
    }

    bool isEmpty(){
        return this->first == nullptr ? true : false;
    }

    friend ostream& operator<<(ostream& output, Stack &p){
        output<<"[";
        if(!p.isEmpty()){
            Node* n = p.first;
            while(n != nullptr){
                if(n!=p.first)output<<", ";
                output<<n->data;
                n = n->next;
            }
        }
        output<<"]";
        return output;
    }

};


int main(){
    
    Stack<int> p;
    cout<<p<<'\n';
    for(int i=0;i<10;i++){
        p.push(i);
    }
    cout<<p<<'\n';
    while(!p.isEmpty()){
        cout<<p.top()<<' '<<p<<'\n';
        p.pop();
    }
    cout<<p<<'\n';

    
cout<<"Pruebas\n";
    for(int i=0;i<10;i++) p.push(i);
    cout<<p<<'\n';
    for(int i=0;i<15;i++) cout<<p.pop()<<' '; cout<<'\n';
    cout<<p<<'\n';
    for(int i=0;i<15;i++) cout<<p.top()<<' '; cout<<'\n';
    cout<<p<<'\n';

}

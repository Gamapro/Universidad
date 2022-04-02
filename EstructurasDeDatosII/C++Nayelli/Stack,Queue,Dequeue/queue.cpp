#include <iostream>
using namespace std;

template<class T>
class Queue{
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
    Node *last;

    Queue(){ first = nullptr; last = nullptr; }

    ~Queue(){  
        Node* n = this->first;
        while(n != nullptr){
            Node* aux = n;
            n = n->next;
            delete aux;
        }
        cout<<"~Queue Delete\n";
    }

    T pop(){
        if(this->first == nullptr){
            return (T)NULL;
        }
        Node* aux = this->first;
        if(this->first == this->last){
            this->last = nullptr;
            this->first = nullptr;
        }else{
            this->first = this->first->next;
        }
        T dato = aux->data;
        delete aux;
        return dato;
    }

    void push(T data){
        Node* n = new Node(data);
        if(this->last == nullptr){
            this->first = this->last = n;
            return;
        }
        this->last->next = n;
        this->last = n;
    }

    bool isEmpty(){
        return this->first == nullptr ? true : false;
    }

    T front(){
        return this->first == nullptr ? (T)NULL : this->first->data;
    }

    friend ostream& operator<<(ostream& output, Queue &q){
        output<<"[";
        if(!q.isEmpty()){
            Node* n = q.first;
            while(n != nullptr){
                if(n!=q.first)output<<", ";
                output<<n->data;
                n = n->next;
            }
        }
        output<<"]";
        return output;
    }

};


int main(){
    
    Queue<int> q;
    cout<<q<<'\n';
    for(int i=0;i<10;i++){
        q.push(i);
    }
    cout<<q<<'\n';
    while(!q.isEmpty()){
        cout<<q.front()<<' '<<q<<'\n';
        q.pop();
    }
    cout<<q<<'\n';

cout<<"Pruebas\n";

    for(int i=0;i<10;i++) q.push(i);
    cout<<q<<'\n';
    for(int i=0;i<15;i++) cout<<q.pop()<<' '; cout<<'\n';
    cout<<q<<'\n';
    for(int i=0;i<15;i++) cout<<q.front()<<' '; cout<<'\n';
    cout<<q<<'\n';

}

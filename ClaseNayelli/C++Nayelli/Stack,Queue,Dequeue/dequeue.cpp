#include <iostream>
using namespace std;

template<class T>
class Dequeue{
public:
    
    class Node{
    public:
        Node *next;
        Node *prev;
        T data;

        Node(){ 
            this->next = nullptr;
            this->prev = nullptr; 
        }

        Node(T data){
            this->next = nullptr;
            this->prev = nullptr; 
            this->data = data;
        }

        ~Node(){
            cout<<"  ~Node("<<data<<")\n";
        }

        friend ostream& operator<<(ostream& output,const Node& n){
            output<< n.data ;
            return output;
        }

    };

    Node *first;
    Node *last;

    Dequeue(){ first = nullptr; last = nullptr; }

    ~Dequeue(){  
        Node* n = this->first;
        while(n != nullptr){
            Node* aux = n;
            n = n->next;
            delete aux;
        }
        cout<<"~Dequeue Delete\n";
    }

    void push_front(T data){
        Node* n = new Node(data);
        if(this->first == nullptr){
            this->first = this->last = n;
            return;
        }
        this->first->prev = n;
        n->next = this->first;
        this->first = n;
        return;
    }

    void push_back(T data){
        Node* n = new Node(data);
        if(this->last == nullptr){
            this->first = this->last = n;
            return;
        }
        this->last->next = n;
        n->prev = this->last;
        this->last = n;
        return;
    }

    T pop_front(){
        if(this->first == nullptr){
            return (T)NULL;
        }
        Node* aux = this->first;
        if(this->first == this->last){
            this->first = this->last = nullptr;
        }else{
            this->first = this->first->next;
            this->first->prev = nullptr;
        }
        T cosa = aux->data;
        delete aux;
        return cosa;
    }

    T pop_back(){
        if(this->last == nullptr){
            return (T)NULL;
        }
        Node* aux = this->last;
        if(this->first == this->last){
            this->first = this->last = nullptr;
        }else{
            this->last = this->last->prev;
            this->last->next = nullptr;
        }
        T cosa = aux->data;
        delete aux;
        return cosa;
    }

    bool isEmpty(){
        return this->first == nullptr ? true : false;
    }

    T front(){
        return this->first == nullptr ? (T)NULL : this->first->data;
    }

    T back(){
        return this->last == nullptr ? (T)NULL : this->last->data;
    }

    friend ostream& operator<<(ostream& output, Dequeue &q){
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
    
    Dequeue<int> q;
    for(int i=0;i<5;i++) q.push_front(i);
    cout<<q<<'\n';
    for(int i=5;i<10;i++) q.push_back(i);
    cout<<q<<'\n';
    for(int i=0;i<15;i++) cout<<q.pop_front()<<' '; cout<<'\n';
    cout<<q<<'\n';
    for(int i=0;i<15;i++) cout<<q.front()<<' '; cout<<'\n';
    cout<<q<<'\n';


    for(int i=10;i<15;i++) q.push_back(i);
    cout<<q<<'\n';
    for(int i=5;i<10;i++) q.push_front(i);
    cout<<q<<'\n';
    for(int i=0;i<2;i++) cout<<q.front()<<' ';
    for(int i=0;i<2;i++) cout<<q.back()<<' '; cout<<'\n';
    cout<<q<<'\n';
    for(int i=0;i<15;i++) cout<<q.pop_back()<<' '; cout<<'\n';
    cout<<q<<'\n';

}

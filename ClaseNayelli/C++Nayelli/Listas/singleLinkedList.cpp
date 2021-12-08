#include <iostream>
using namespace std;



class Node{
public:
    Node* next; 
    int data;
    Node();
    Node(int);
    ~Node();
    friend ostream& operator<<(ostream& output, const Node& n){
        output<<"( data: "<<n.data<<", next: "<<n.next<<")";
        return output;
    }
};

Node::Node(){ next = nullptr; }

Node::Node(int data){ 
    next = nullptr;
    this->data = data;
}

Node::~Node(){
    cout<<"  ~Node("<<data<<")"<<endl;
}





class SingleLinkedList{
public:
    Node* head;
    SingleLinkedList();
    SingleLinkedList(Node*);
    SingleLinkedList(int);
    ~SingleLinkedList();
    void insert_head(int);
    void insert_tail(int);
    void remove(int);
    void print();
    void reverse();
    friend ostream& operator<<(ostream& output, const SingleLinkedList &l){
        output<<"[";
        Node* aux = l.head;
        while(aux != nullptr){
            output<<*aux<<' ';
            aux = aux->next;
        }
        output<<"]\n";
        return output;
    }
};

SingleLinkedList::SingleLinkedList(){ head = nullptr; }

SingleLinkedList::SingleLinkedList(Node* head){ 
    this->head = head;
}

SingleLinkedList::SingleLinkedList(int data){ 
    Node* n = new Node(data);
    this->head = n;
}

SingleLinkedList::~SingleLinkedList(){
    cout<<"  ~SinglyLinkedList()"<<endl;
    if( head == nullptr )
        return;
    Node* aux = head;
    Node* aux2 = aux->next;
    while( aux != nullptr){
        delete aux;
        aux = aux2;
        if( aux2 != nullptr ) aux2 = aux2->next;
    }
}

void SingleLinkedList::insert_head(int data){
    Node* n = new Node(data);
    if(head == nullptr){
        head = n;
    }else{
        n->next = this->head;
        this->head = n;
    }
}

void SingleLinkedList::insert_tail(int data){
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

void SingleLinkedList::remove(int data){
    if(head == nullptr) return;
    if(head->data == data){
        Node* ndelete = head;
        head = head->next;
        delete ndelete;
    }else{
        Node* aux = head;
        while(aux != nullptr && aux->next != nullptr && aux->next->data != data){
            aux = aux->next;
        }
        if(aux->next != nullptr && aux->next->data == data){
            Node* ndelete = aux->next;
            aux->next = aux->next->next;
            delete ndelete;
        }
    }
    return;
}

void SingleLinkedList::print(){
    cout<<"[";
    Node* aux = head;
    while(aux != nullptr){
        cout<<aux->data<<' ';
        aux = aux->next;
    }
    cout<<"]\n";
    return;
}

void SingleLinkedList::reverse(){
    Node* toy = this->head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(toy != nullptr){
        next = toy->next;
        toy->next = prev;
        prev = toy;
        toy = next;
    }
    this->head = prev;
    return;
}

int main(){
    
    SingleLinkedList lis;
    lis.insert_head(3);
    lis.insert_head(4);
    lis.insert_head(5);
    lis.insert_head(6);
    lis.insert_tail(1);
    lis.insert_tail(9);
    lis.insert_tail(8);
    lis.insert_tail(10);
    // [6,5,4,3,1,9,8,10]
    cout<<lis<<'\n';
    lis.print();
    lis.reverse();
    lis.print();
    lis.remove(10);
    lis.remove(6);
    lis.remove(1);
    lis.remove(3);
    lis.remove(5);
    lis.remove(8);
    lis.print();
}

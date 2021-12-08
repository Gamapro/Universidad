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





class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList();
    CircularLinkedList(Node*);
    CircularLinkedList(int);
    ~CircularLinkedList();
    void insert_head(int);
    void insert_tail(int);
    void remove(int);
    void print();
    friend ostream& operator<<(ostream& output, const CircularLinkedList &l){
        output<<"[";
        if(l.head != nullptr){
            Node* aux = l.head;
            while(aux->next != l.head){
                output<<*aux<<' ';
                aux = aux->next;
            }
            output<<*aux<<' ';
        }
        output<<"]\n";
        return output;
    }
};

CircularLinkedList::CircularLinkedList(){ head = nullptr; }

CircularLinkedList::CircularLinkedList(Node* head){ 
    this->head = head;
    head->next = head;
}

CircularLinkedList::CircularLinkedList(int data){ 
    Node* n = new Node(data);
    this->head = n;
    head->next = head;
}

CircularLinkedList::~CircularLinkedList(){
    cout<<"  ~SinglyLinkedList()"<<endl;
    if( head == nullptr )
        return;
    Node* aux = head->next;
    Node* aux2 = aux->next;
    while( aux != head){
        delete aux;
        aux = aux2;
        if( aux2 != nullptr ) aux2 = aux2->next;
    }
    delete head;
    return;
}

void CircularLinkedList::insert_head(int data){
    Node* n = new Node(data);
    if(head == nullptr){
        head = n;
        head->next = head;
    }else{
        n->next = this->head;
        Node* aux = this->head;
        while(aux->next != head){
            aux = aux->next;
        }
        aux->next = n;
        this->head = n;
    }
}

void CircularLinkedList::insert_tail(int data){
    Node* n = new Node(data);
    if(head == nullptr){
        head = n;
        head->next = head;
    }else{
        n->next = this->head;
        Node* aux = this->head;
        while(aux->next != head){
            aux = aux->next;
        }
        aux->next = n;
    }
}

void CircularLinkedList::remove(int data){
    if(head == nullptr) return;
    if(head->data == data){
        Node* ndelete = head;
        if(head->next == head){
            head = nullptr;   
        }else{
            Node* aux = this->head;
            while(aux->next != head){
                aux = aux->next;
            }
            aux->next = aux->next->next;
            head = aux->next;
        }
        delete ndelete;
    }else{
        Node* aux = head;
        while(aux->next != head && aux->next->data != data){
            aux = aux->next;
        }
        if(aux->next != head && aux->next->data == data){
            Node* ndelete = aux->next;
            aux->next = aux->next->next;
            delete ndelete;
        }
    }
    return;
}

void CircularLinkedList::print(){
    if(head == nullptr) {
        cout<<"[]\n";
        return;
    }
    cout<<"[";
    Node* aux = head;
    while(aux->next != head){
        cout<<aux->data<<' ';
        aux = aux->next;
    }
    cout<<aux->data;
    cout<<"]\n";
    return;
}


int main(){
    CircularLinkedList lis;    
    lis.print();
    cout<<lis<<'\n';
}

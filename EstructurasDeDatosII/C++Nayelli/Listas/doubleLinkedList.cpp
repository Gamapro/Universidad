#include <iostream>
using namespace std;


class DoubleNode{
public:
    DoubleNode* next; 
    DoubleNode* prev; 
    int data;
    DoubleNode();
    DoubleNode(int);
    ~DoubleNode();
    friend ostream& operator<<(ostream& output, const DoubleNode& n){
        output<<"( data: "<<n.data<<", next: "<<n.next<<", prev: "<<n.prev<<")";
        return output;
    }
};

DoubleNode::DoubleNode(){ next = nullptr; prev=nullptr; }

DoubleNode::DoubleNode(int data){ 
    next = nullptr;
    prev = nullptr;
    this->data = data;
}

DoubleNode::~DoubleNode(){
    cout<<"  ~DoubleNode("<<data<<")"<<endl;
}



class DoubleLinkedList{
public:
    DoubleNode* head;
    DoubleNode* tail;
    DoubleLinkedList();
    DoubleLinkedList(DoubleNode*);
    DoubleLinkedList(int);
    ~DoubleLinkedList();
    void push_back(int);
    void pop_back();
    void push_front(int);
    void pop_front();
    void remove(int);
    void print();
    void print_reverse();
    void reverse();
    friend ostream& operator<<(ostream& output, const DoubleLinkedList &l){
        output<<"[";
        DoubleNode* aux = l.head;
        while(aux != nullptr){
            output<<*aux<<' ';
            aux = aux->next;
        }
        output<<"]\n";
        return output;
    }
};

DoubleLinkedList::DoubleLinkedList(){ head = tail = nullptr; }

DoubleLinkedList::DoubleLinkedList(DoubleNode* head){ 
    this->head = head;
    this->tail = head;
}

DoubleLinkedList::DoubleLinkedList(int data){ 
    DoubleNode* n = new DoubleNode(data);
    this->head = head;
    this->tail = head;
}

DoubleLinkedList::~DoubleLinkedList(){
    cout<<"  ~DoubleLinkedList()"<<endl;
    if( head == nullptr )
        return;
    DoubleNode* aux = head;
    DoubleNode* aux2 = aux->next;
    while( aux != nullptr){
        delete aux;
        aux = aux2;
        if( aux2 != nullptr ) aux2 = aux2->next;
    }
}

void DoubleLinkedList::push_front(int data){
    DoubleNode* n = new DoubleNode(data);
    if(head == nullptr){
        head = n;
        tail = n;
    }else{
        n->next = this->head;
        this->head->prev = n;
        this->head = n;
    }
    return;
}

void DoubleLinkedList::pop_front(){
    if(head == nullptr){
        return;
    }else{
        DoubleNode* aux = head;
        head = head->next;
        if(head != nullptr)head->prev = nullptr;
        else{
            head = nullptr;
            tail = nullptr;
        }
        delete aux;
        return;
    }
}


void DoubleLinkedList::push_back(int data){
    DoubleNode* n = new DoubleNode(data);
    if(head == nullptr){
        head = n;
        tail = n;
    }else{
        n->prev = this->tail;
        tail->next = n;
        this->tail = n;
    }
}

void DoubleLinkedList::pop_back(){
    if(tail == nullptr){
        return;
    }else{
        DoubleNode* aux = this->tail;
        tail = tail->prev;
        if(tail != nullptr) tail->next = nullptr;
        else{
            head = nullptr;
            tail = nullptr;
        }
        delete aux;
        return;
    }
}


void DoubleLinkedList::remove(int data){
    if(head == nullptr) return;
    if(head->data == data){
        DoubleNode* ndelete = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }else{
            tail = nullptr;
        }
        delete ndelete;
    }else if(tail->data == data){
        DoubleNode* ndelete = tail;
        tail = tail->prev;
        if(tail != nullptr){
            tail->next = nullptr;
        }else{
            head = nullptr;
        }
        delete ndelete;
        
    }else{
        DoubleNode* aux = head;
        while(aux != nullptr && aux->next != nullptr && aux->next->data != data){
            aux = aux->next;
        }
        if(aux->next != nullptr && aux->next->data == data){
            DoubleNode* ndelete = aux->next;
            aux->next = aux->next->next;
            aux->next->prev = aux;
            delete ndelete;
        }
    }
    return;
}

//愛

void DoubleLinkedList::print(){
    cout<<"[";
    DoubleNode* aux = head;
    while(aux != nullptr){
        cout<<aux->data<<' ';
        aux = aux->next;
    }
    cout<<"]\n";
    return;
}

void DoubleLinkedList::print_reverse(){
    cout<<"[";
    DoubleNode* aux = tail;
    while(aux != nullptr){
        cout<<aux->data<<' ';
        aux = aux->prev;
    }
    cout<<"]\n";
    return;
}

int main(){
    DoubleLinkedList lista;
  for( int i = 0; i < 100; i++ )
    lista.push_front(i);
cout << 1;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 105; i++ )
    lista.remove(i);
cout << 2;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 100; i++ )
    lista.push_front(i);
cout << 3;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 105; i++ )
    lista.pop_front();
cout << 4;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 100; i++ )
    lista.push_front(i);
cout << 5;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 105; i++ )
    lista.pop_back();
cout << 6;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 100; i++ )
    lista.push_back(i);
cout << 7;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 105; i++ )
    lista.pop_back();
cout << 8;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 100; i++ )
    lista.push_back(i);
cout << 9;
    lista.print();
    lista.print_reverse();
  for( int i = 0; i < 105; i++ )
    lista.pop_front();
cout << 10;
    lista.print();
    lista.print_reverse();
  cout << lista << endl;
  lista.push_front(0);
  lista.push_front(5);
  lista.push_front(1);
  cout << lista << endl;
cout << "jaja";
  lista.print_reverse();
	cout << "hola" << endl;
  return 0;


    lista.print();
    lista.print_reverse();
}

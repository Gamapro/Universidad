#include<bits/stdc++.h>
using namespace std;

template <class T>
class BST{
public:

    template <class H>
    class Node{
    public:
        Node<H> *left = nullptr, *right = nullptr;
        H data = (H)NULL;

        Node<H>(){}
        
        Node<H>(H data){
            this->data = data;
        }
            
        ~Node<H>(){
            cout<<"~Delete: "<<data<<'\n';
            return;
        }

    };
    
    Node<T>* root = nullptr;

    BST(){}

    ~BST(){
        cout<<"~Delete BST"<<'\n';
        toposort(this->root);
    }

    void insert(T data){
        Node<T>* n = new Node<T>(data);
        Node<T>* aux = this->root;
        if(aux == nullptr){
            this->root = n;
            return;
        }
        while(true){
            if(data <= aux->data){
                if(aux->left == nullptr){
                    aux->left = n;
                    return;
                }else{
                    aux = aux->left;
                }
            }else{
                if(aux->right == nullptr){
                    aux->right = n;
                    return;
                }else{
                    aux = aux->right;
                }
            }
        }
    }

    bool contains(T data){
        Node<T>* n = this->root;
        while(n != nullptr){
            if(n->data == data){
                return true;
            }else if(data <= n->data){
                n = n->left;
            }else{
                n = n->right;
            }
        }
        return false;
    }

    Node<T>* nodoChiquito(Node<T>* root){
        while(root->right != nullptr){
            root = root->right;
        }
        return root;
    }

    void remove(T data, Node<T>* esteSi = nullptr){
        // ROOT = NULL
        if(this->root == nullptr){
            return;
        }
        Node<T>* ant = nullptr;
        Node<T>* aux = this->root;
        while(esteSi != nullptr && aux != esteSi && aux->data == data){
            ant = aux;
            if(data <= aux->data){
                aux = aux->left;
            }else{
                aux = aux->right;
            }
        }
        while(aux != nullptr && aux->data != data){
            ant = aux;
            if(data <= aux->data){
                aux = aux->left;
            }else{
                aux = aux->right;
            }
            while(esteSi != nullptr && aux != esteSi && aux->data == data){
                ant = aux;
                if(data <= aux->data){
                    aux = aux->left;
                }else{
                    aux = aux->right;
                }
            }
        }
        // NO ESTA - REGRESO
        if(aux == nullptr){
            return;
        }

        // CASO 1 : HOJA
        if(aux->left == nullptr && aux->right == nullptr && aux->data == data){
            // Si es root, reinicio todo el arbol
            if(aux == this->root){
                this->root = nullptr;
            }else{ // El anterior lo contiene
                if(ant->left == aux){
                    ant->left = nullptr;
                }else{
                    ant->right = nullptr;
                }
            }
            delete aux;
        }

        // CASO 3 : DOS HIJOS
        else if(aux->right != nullptr && aux->left != nullptr){
            // Sacar nodo mas pequeño mas grande del que tengo
            Node<T>* nodoCambio = nodoChiquito(aux->left);
            // Y lo elimino, pero guardo el valor antes
            T valNodo = nodoCambio->data;
            // Recursivamente uso la misma funcion delete 
            remove(valNodo, nodoCambio);
            // Y cambio el valor por elvalor del nodo eliminado
            aux->data = valNodo;
            // No elimino el nodo, porque recursivamente elimino
            // el nodo que cotenia el valor anterior
        }

        // CASO 2 : 1 HIJO
        else{

            // Sacar el unico hijo
            Node<T>* hijo;
            if(aux->left != nullptr){
                hijo = aux->left;
            }else{
                hijo = aux->right;
            }

            // Si es mi root
            if(aux == this->root){
                this->root = hijo;
            }else{
                if(aux == ant->left){
                    ant->left = hijo;
                }else{
                    ant->right = hijo;
                }
            }

            delete aux;
        }
        
        return;
    }
    
    void mostrarArbol(Node<T>* root , int cont=0){
        if(root == nullptr){
            return;
        }
        mostrarArbol(root->right, cont+1);
        for(int i=0;i<cont;i++)cout<<"  ";
        cout<<root->data<<'\n';
        mostrarArbol(root->left, cont+1);

    }
    
    void toposort(Node<T>* root){
        if(root == nullptr) return;
        toposort(root->left);
        toposort(root->right);
        delete root;
        return;
    }

    void DFS(){
        stack<Node<T>*> st; 
        st.push(this->root);
        cout<<"[";
        while(!st.empty()){
            Node<T>* n = st.top();
            st.pop();
            if(n != this->root){
                cout<<", ";
            }
            cout<<n->data;
            if(n->right != nullptr) st.push(n->right);
            if(n->left != nullptr) st.push(n->left);
        }
        cout<<"]\n";
        return;
    }

    void BFS(){
        queue<Node<T>*> st; 
        st.push(this->root);
        cout<<"[";
        while(!st.empty()){
            Node<T>* n = st.front();
            st.pop();
            if(n != this->root){
                cout<<", ";
            }
            cout<<n->data;
            if(n->left != nullptr) st.push(n->left);
            if(n->right != nullptr) st.push(n->right);
        }
        cout<<"]\n";
        return;
    }

    void preorder(Node<T>* root, bool ya = false){
        if(root == nullptr) return;
        if(root== this->root)cout<<"[";
        if(ya)cout<<", ";
        cout<<root->data;
        preorder(root->left,1);
        preorder(root->right,1);
        if(root== this->root)cout<<"]\n";
        return;
    }
    
    bool inorder(Node<T>* root, bool ya = false){
        if(root == nullptr) return ya;
        if(root== this->root)cout<<"[";
        ya = max(ya,inorder(root->left,ya));
        if(ya)cout<<", ";
        cout<<root->data;
        ya = true;
        inorder(root->right,1);
        if(root== this->root)cout<<"]\n";
        return 1;
    }

    bool postorder(Node<T>* root, bool ya = false){
        if(root == nullptr) return 0;
        if(root== this->root)cout<<"[";
        ya = max(postorder(root->left,ya),ya);
        ya = max(postorder(root->right,ya),ya);
        if(ya)cout<<", "; 
        cout<<root->data;
        ya = true;
        if(root== this->root)cout<<"]\n";
        return ya;
    }

    void print(){
        DFS();
        BFS();
        preorder(this->root);
        inorder(this->root);
        postorder(this->root);
        mostrarArbol(this->root);
    }

};

int main(){
    
    BST<int> bst;
    bst.insert(5);
    bst.insert(4);
    bst.insert(6);
    bst.insert(3);
    bst.insert(9);
    bst.insert(1);
    bst.insert(8);
    bst.insert(3);
    bst.insert(3);
    bst.insert(3);
    bst.insert(3);
    bst.insert(3);
    bst.insert(7);
    bst.insert(0);
    bst.insert(2);
    bst.mostrarArbol(bst.root);

    bst.remove(4);
    bst.mostrarArbol(bst.root);
    bst.remove(2);
    bst.mostrarArbol(bst.root);
    bst.remove(3);
    bst.remove(3);
    bst.mostrarArbol(bst.root);
    bst.print();

    BST<char> b;
    b.insert('A');
    b.insert('B');
    b.insert('A');
    b.insert('B');
    b.remove('A');
    b.print();
}

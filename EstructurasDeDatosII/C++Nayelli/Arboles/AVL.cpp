#include<bits/stdc++.h>
using namespace std;

template <class T>
class AVL{
public:

    template <class H>
    class Node{
    public:
        Node<H> *left = nullptr, *right = nullptr, *parent = nullptr;
        H data = (H)NULL;
        int balance = 0, height = 1;
        
        // Node<H>* updateBalance(Node<H>* root);

        Node<H>(){}
        
        Node<H>(H data){
            this->data = data;
        }
            
        ~Node<H>(){
            cout<<"~Delete: "<<data<<'\n';
            return;
        }

        Node<H>* insert(Node<H>* node, Node<H>* root){
            if(node->data <= this->data){
                if(this->left == nullptr){
                    node->parent = this;
                    this->left = node;
                }else{
                    this->left->insert(node, root);
                }
            }else{
                if(this->right == nullptr){
                    node->parent = this;
                    this->right = node;
                }
                else{
                    this->right->insert(node, root);
                }
            }
            // Balances
            return updateBalance(root);
            //return root;
        }

        Node<H>* nodoChiquito(Node<H>* root){
            while(root->right != nullptr){
                root = root->right;
            }
            return root;
        }


        Node<H>* remove(H data, Node<H>* root){
            if(root == nullptr){
                return root;
            }
            if(data < root->data){
                root->left = this->remove(data, root->left);
            }else if(data > root->data){
                root->right = this->remove(data, root->right);
            }else{
                
                // No hijo izquierdo
                if(root->left == nullptr){
                    Node<H>* aux = root->right;
                    delete root;
                    return aux;
                }

                // Tengo al menos el hijo izquierdo
                if(root->right == nullptr){
                    Node<H>* aux = root->left;
                    delete root;
                    return aux;
                }

                // Tengo ambos hijos 
                Node<H>* aux = this->nodoChiquito(root->left);
                root->data = aux->data;
                root->left = Node::remove(aux->data, root->left);
            }
            return updateBalance(root);
        }

        Node<H>* rotateRight(Node<H>* node, Node<H>* root){
        // Determinar nodo a y b, parent y subarbol s2
            Node<H> *parent = node->parent, *a = node, *b = a->left ,*s2 = b->right;
        // Asignar subarbol s2 como hijo de a
            a->left = s2;
            if(s2 != nullptr){
                s2->parent = a;
            }
        // Asignar a como hijo de b
            b->right = a;
            a->parent = b;
        // Reseteo padre de b
            b->parent = parent;

        // Root del arbol lol
            if(parent == nullptr){
                root = a->updateBalance(root);
                root = b->updateBalance(root);
                return b; // La nueva raiz
            }
        // No-Root
            else if(parent->left == a) parent->left = b;
            else if(parent->right == a) parent->right = b;
        // Regreso la raiz original
            root = a->updateBalance(root);
            root = b->updateBalance(root);
            return root; // Raiz original
        }
 
        Node<H>* rotateLeft(Node<H>* node, Node<H>* root){
        // Determinar nodo a y b, parent y subarbol s2
            Node<H> *parent = node->parent, *a = node, *b = a->right ,*s2 = b->left;
        // Asignar subarbol s2 como hijo de a
            a->right = s2;
            if(s2 != nullptr){
                s2->parent = a;
            }
        // Asignar a como hijo de b
            b->left = a;
            a->parent = b;
        // Reseteo padre de b
            b->parent = parent;

        // Root del arbol lol
            if(parent == nullptr){
                root = a->updateBalance(root);
                root = b->updateBalance(root);
                return b; // La nueva raiz
            }
        // No-Root
            else if(parent->left == a) parent->left = b;
            else if(parent->right == a) parent->right = b;
        // Regreso la raiz original
            root = a->updateBalance(root);
            root = b->updateBalance(root);
            return root; // Raiz original
        } 

        Node<H>* updateBalance(Node<H>* root){
            int hl = (this->left == nullptr ? 0 : this->left->height);
            int hr = (this->right == nullptr ? 0 : this->right->height);
            this->height = max(hl, hr) + 1;
            this->balance = hl - hr;

            if(this->balance <= -2 && this->right->balance <=0){
                root = rotateLeft(this,root);
            }else if(this->balance <= -2 && this->right->balance == 1){
                root = rotateRight(this->right, root);
                root = rotateLeft(this, root);
            }else if(this->balance >= 2 && this->left->balance == -1){
                root = rotateLeft(this->left, root);
                root = rotateRight(this, root);
            }else if(this->balance >= 2 && this->left->balance >= 0){
                root = rotateRight(this, root);
            }
            return root;
        }
        

    };
    
    Node<T>* root = nullptr;

    AVL(){}

    ~AVL(){
        cout<<"~Delete AVL"<<'\n';
        toposort(this->root);
    }

    void insert(T data){
        Node<T>* nodo = new Node<T>(data);
        if(this->root == nullptr){
            this->root = nodo;
        }else{
            this->root = this->root->insert(nodo, this->root); 
        }
        return;
    }

    void remove(T data){
        if(this->root == nullptr){
            return;
        }else{
            this->root = this->root->remove(data, this->root); 
        }
        return;
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
    AVL<int> avl;
    for(int i=0;i<10;i++) avl.insert(i);
    for(int i=0;i>-10;i--) avl.insert(i);
    avl.mostrarArbol(avl.root);

    avl.remove(3);
    avl.remove(4);
    avl.remove(-3);
    for(int i=0;i>-10;i--)
    avl.remove(i);

    avl.mostrarArbol(avl.root);
    avl.print();

    AVL<char> avl2;
    for(int i=0;i<10;i++) avl2.insert(i+'a');
    avl2.insert('f');
    avl2.insert('g');
    avl2.insert('a');
    avl2.insert('e');
    avl2.print();
}

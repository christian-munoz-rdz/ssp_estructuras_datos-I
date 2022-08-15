#include "Node.h"

class Btree{
public:
    Node* root;

    Btree();
    ~Btree();

    void insertRoot(int);
    void insert(int,Node*);

    Node* searchRoot(int);
    Node* search(int, Node*);

    void searchNameRoot(string);
    void searchName(Node*,string);

    Node* min();
    Node* max();

    void findPredSuc(Node*,Node*&, Node*&,int);

    void edit(Node*);

    Node* deleteNode(Node*,int);

    void inOrderPrintRoot();
    void inOrderPrint(Node*);

    void preOrderPrintRoot();
    void preOrderPrint(Node*);

    void postOrderPrintRoot();
    void postOrderPrint(Node*);
};

Btree::Btree(){
    root = NULL;
}

void Btree::insertRoot(int id){
    if (root != NULL){
        insert(id,root);
    }
    else{
        root = new Node(id);
    }  
}

void Btree::insert(int id, Node* leaf){
    if(id < leaf->id){
        if (leaf->left!=NULL){
          insert(id,leaf->left);
        }
        else{
            Node* aux = new Node(id);
            leaf->left = aux;
        }  
    }
    else if (id>=leaf->id){
        if (leaf->right != NULL){
          insert(id,leaf->right);
        }
        else{
            Node* aux = new Node(id);
            leaf->right = aux;
        } 
    }   
}

Node* Btree::searchRoot(int id){
    return search(id,root);
}

Node* Btree::search(int id, Node* leaf){
    if (leaf != NULL){
        if (id == leaf->id){
            return leaf;
        }
        else if (id < leaf->id){
            return search(id,leaf->left);
        }
        else{
            return search(id, leaf->right);
        }
    }
    else{
        return NULL;
    }
}

void Btree::searchNameRoot(string name){
    searchName(root,name);
}

void Btree::searchName(Node* leaf,string name){
    if (leaf!=NULL){
        if (leaf->name==name){
            leaf->show();
            Node* pre = NULL, *suc = NULL;
            findPredSuc(root,pre,suc,leaf->id);
            if (pre != NULL)
                cout << "El predecesor es " << pre->name << endl;
            else
                cout << "No hay predecesor"<<endl; 
            if (suc != NULL)
                cout << "El succesor es " << suc->name<<endl;
            else
                cout << "No hay succesor"<<endl;
            return;
        }
        searchName(leaf->left,name);
        searchName(leaf->right,name);
    }
}

Node* Btree::min(){

    if(root){

        Node* min = root;
        while (min->left!=NULL){
            min = min->left;
        }
        return min;
    }
    else
        return NULL;

}

Node* Btree::max(){
    if (root){

        Node* max = root;
        while (max->right!=NULL){
            max = max->right;
        }
        return max;
    }
    else
        return NULL;

    
    
}

void Btree::findPredSuc(Node* begin, Node*& pre, Node*& suc, int id){
    if (begin == NULL)  
        return ;
 
    if(begin->id == id){
        if (begin->left != NULL){
            Node* tmp = begin->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }

        if (begin->right != NULL){
            Node* tmp = begin->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    if(begin->id > id){
        suc = begin ;
        findPredSuc(begin->left, pre, suc, id) ;
    }
    else{
        pre = begin ;
        findPredSuc(begin->right, pre, suc, id) ;
    }
}

void Btree::edit(Node* leaf){
    leaf->edit();
}

Node* Btree::deleteNode(Node* root, int id){
    if (root == NULL)
        return root;
 
    if (root->id > id) {
        root->left = deleteNode(root->left, id);
        return root;
    }
    else if (root->id < id) {
        root->right = deleteNode(root->right, id);
        return root;
    }
 
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    else {
 
        Node* succParent = root;
 
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        root->id = succ->id;
        root->name = succ->name;
        root->direction = succ->direction;
        root->email = succ->email;
 
        delete succ;
        return root;
    }
}

void Btree::inOrderPrintRoot(){
    
    if (root){
        inOrderPrint(root);
        cout << "\n";
    }
    else
        cout<<"Arbol vacio"<<endl;
    

}

void Btree::inOrderPrint(Node* leaf){
    if (leaf!=NULL){
        inOrderPrint(leaf->left);
        leaf->show();
        inOrderPrint(leaf->right);
    }
}

void Btree::preOrderPrintRoot(){
    if (root){
        preOrderPrint(root);
        cout<<"\n";        
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::preOrderPrint(Node* leaf){
    if (leaf!=NULL){
        leaf->show();
        inOrderPrint(leaf->left);
        inOrderPrint(leaf->right);
    }
    
}

void Btree::postOrderPrintRoot(){

    if (root){
        postOrderPrint(root);
        cout<<"\n";
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::postOrderPrint(Node* leaf){
    
    if (leaf != NULL){
        inOrderPrint(leaf->left);
        inOrderPrint(leaf->right);
        leaf->show();
    }
}
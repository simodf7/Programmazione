#include "BST.h"


template<typename T>
void BST<T>::preOrderTreeWalk(BSTNode<T>* x){
    if (x != nullptr){
        std::cout << x->key << "\n";
        preOrderTreeWalk(x->left);
        preOrderTreeWalk(x->right);
    }
    
};

template<typename T>
void BST<T>::inOrderTreeWalk(BSTNode<T>* x){  

    if (x != nullptr){
        inOrderTreeWalk(x->left);
        std::cout << x->key << "\n";
        inOrderTreeWalk(x->right);
    }
    
};

template<typename T>
void BST<T>::postOrderTreeWalk(BSTNode<T>* x){  

    if (x != nullptr){
        postOrderTreeWalk(x->left);
        postOrderTreeWalk(x->right);
        std::cout << x->key << "\n";
    }
    
};



template<typename T>
BSTNode<T>* BST<T>::search(BSTNode<T>* x, const T& k){  

    while(x != nullptr){
        if(x->key == k){
            break;
        }
        else if (x->key < k) {x = x->right;}
        else {x = x->left;}
    }
   
    return x;

};




template<typename T>
BSTNode<T>* BST<T>::minimum(BSTNode<T>* subroot){  

    BSTNode<T>* x = subroot;

    if (x != nullptr){
        while(x->left != nullptr){  // sempre a sinistra finche il prossimo a sinistra non esiste
            x = x->left;
        }
    }
    

    return x;

};


template<typename T>
BSTNode<T>* BST<T>::maximum(BSTNode<T>* subroot){  

    BSTNode<T>* x = subroot;

    if (x != nullptr){
        while(x->right != nullptr){
            x = x->right;
        }
    }
    
    
    return x;

};

template<typename T>
BSTNode<T>* BST<T>::successor(const T& k){  

    BSTNode<T>* succ = nullptr;
    
    BSTNode<T>* x = search(k);
    std::cout << "/Debug x: " << x << "\n";

    // 2 casi: x non ha figlio destro o ha figlio destro
    

    if(x->right != nullptr){ // x ha figlio destro
        succ = minimum(x->right);
    }
    else{  // x non ha figlio destro, devo tornare indietro per trovare l'antenato che ha x come figlio sinistro
        succ = x->parent;
        while(succ != nullptr && succ->right == x){ // fin quando succ non parente di root e succ == figlio destro
            x = succ;
            succ = x->parent;
        }    
    }



    std::cout << "Successor: " << succ->key << "\n";
    return succ;
    

    
};



template<typename T>
BSTNode<T>* BST<T>::predecessor(const T& k){    // duale del successore

    BSTNode<T>* prev = nullptr;
    BSTNode<T>* x = search(k);

    if(x->left != nullptr){ 
        prev = maximum(x->left);
    }
    else{  
        prev = x->parent;
        while(prev != nullptr && prev->left == x){ //finquando prev non parente di root e  prev == figlio sinistro
            x = prev;
            prev = x->parent;
        }    
    }
    
    std::cout << "Predecessor: " << prev->key << "\n";
    return prev;
    

    
};






template<typename T>
void BST<T>::insert(const T& k){  

    BSTNode<T>* x = new BSTNode<T>(k);
   // std::cout << "Debug: " << x << "\n"; 
    BSTNode<T>* y = root;
    BSTNode<T>* z = nullptr;

    if (search(k) != nullptr) return; // if then key is already inserted, we do not have to insert it

    while(y != nullptr){

        z = y;  // mi salvo il nodo precedente per evitare che diventi nullptr
        if ( x->key < y->key) {
            y = y->left;
        }
        else  y = y->right;
    }

    x->parent = z;  

    if (z == nullptr){  // albero vuoto
        root = x;
    }  
    else{
        if(x->key < z->key){
            z->left = x;
        }
        else z->right = x;

    }



};

template<typename T>
void BST<T>::recInsert(BSTNode<T>* x, const T& k){

    //std::cout << x->key << "\n";

    // if( x->left  == nullptr || x->left == nullptr) {
    //     if(x->key == k) return;
    //     else if(x->key > k) { x->left = new BSTNode<T>(k);}
    //     else { x->right = new BSTNode<T>(k);}
    // }
    // else if(x->key > k){recInsert(x->left, k);}
    // else {recInsert(x->right,k);}

    if(x->key == k) return;
    else if(x->key > k){
        if(x->left == nullptr) x->left = new BSTNode<T>(k);
        else recInsert(x->left, k);
    } 
    else if(x->key < k) {
        if(x->right == nullptr) x->right = new BSTNode<T>(k);
        else recInsert(x->right, k);
    }

    
}

template<typename T>
void BST<T>::recInsert(const T& k){

    if(root == nullptr) {root = new BSTNode<T>(k); return;}
    recInsert(root,k);
    
}





template<typename T>
BSTNode<T>* BST<T>::deleteNode(const T& k){  

    BSTNode<T>* z = nullptr;
    BSTNode<T>* x = nullptr;

    if (search(k) == nullptr) return nullptr; // if then key is already inserted, we do not have to insert it

    z = search(k);
    if(z == root) root = nullptr;  // if z is root

    //  No child
    if(z->left == nullptr && z->right == nullptr){
        z = nullptr;
    }
    
    // 1 child
    if (z->left != nullptr){   
        z = z->left;
    }
    else z = z->right;


    // 2 child
    if(z->left && z->right){
        x = successor(z);
        if(x->right) x->parent->left = x->right;
        z = x;
    } 
 

   // da completare


};




template<typename T>
BSTNode<T>* BST<T>::iterativeSearch(BSTNode<T>* x, const T& k){    

    if (x == nullptr) return nullptr;
    if (x->key == k) return x;
    if (x->key < k){
        iterativeSearch(x->left, k);
    } 
    else{
        iterativeSearch(x->right, k);
    }

    
};



template<typename T>
void BST<T>::release(BSTNode<T>* x){
    
    if (x != nullptr){
        release(x->left);
        release(x->right);
       // std::cout << "Deleted: " << x->key << "\n"; 
        x = nullptr;
    }
};




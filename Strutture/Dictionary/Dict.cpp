#include "Dict.h"


template<typename Key, typename Value>
void Dict<Key,Value>::preOrderTreeWalk(DictNode<Key,Value>* x){
    if (x != nullptr){
        std::cout << x->key << ":" << x->value << "\n";
        preOrderTreeWalk(x->left);
        preOrderTreeWalk(x->right);
    }
    
};

template<typename Key, typename Value>
void Dict<Key,Value>::inOrderTreeWalk(DictNode<Key,Value>* x){  

    if (x != nullptr){
        inOrderTreeWalk(x->left);
        std::cout << x->key << ":" << x->value << "\n";
        inOrderTreeWalk(x->right);
    }
    
};

template<typename Key, typename Value>
void Dict<Key,Value>::postOrderTreeWalk(DictNode<Key,Value>* x){  

    if (x != nullptr){
        postOrderTreeWalk(x->left);
        postOrderTreeWalk(x->right);
        std::cout << x->key << ":" << x->value << "\n";
    }
    
};



template<typename Key, typename Value>
DictNode<Key,Value>* Dict<Key,Value>::search(DictNode<Key,Value>* x, const Key& k){  

    while(x != nullptr){
        if(x->key == k){
            break;
        }
        else if (x->key < k) {x = x->right;}
        else {x = x->left;}
    }
   
    return x;

};




template<typename Key, typename Value>
DictNode<Key,Value>* Dict<Key,Value>::minimum(DictNode<Key,Value>* subroot){  

    DictNode<Key,Value>* x = subroot;

    if (x != nullptr){
        while(x->left != nullptr){  // sempre a sinistra finche il prossimo a sinistra non esiste
            x = x->left;
        }
    }
    

    return x;

};


template<typename Key, typename Value>
DictNode<Key,Value>* Dict<Key,Value>::maximum(DictNode<Key,Value>* subroot){  

    DictNode<Key,Value>* x = subroot;

    if (x != nullptr){
        while(x->right != nullptr){
            x = x->right;
        }
    }
    
    
    return x;

};

template<typename Key, typename Value>
DictNode<Key,Value>* Dict<Key,Value>::successor(const Key& k){  

    DictNode<Key,Value>* succ = nullptr;
    
    DictNode<Key,Value>* x = search(k);
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



    std::cout << "Successor: " << succ->key << ":" << succ->value <<  "\n";
    return succ;
    

    
};



template<typename Key, typename Value>
DictNode<Key,Value>* Dict<Key,Value>::predecessor(const Key& k){    // duale del successore

    DictNode<Key,Value>* prev = nullptr;
    DictNode<Key,Value>* x = search(k);

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
    
    std::cout << "Predecessor: " << prev->key << ":" << prev->value <<  "\n";
    return prev;
    

    
};






template<typename Key, typename Value>
void Dict<Key,Value>::insert(const Key& k, const Value& v){  

    DictNode<Key,Value>* x = new DictNode<Key,Value>(k,v);
    DictNode<Key,Value>* y = root;
    DictNode<Key,Value>* z = nullptr;

    //if (search(k) != nullptr) return nullptr; // if then key is already inserted, we do not have to insert it

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

template<typename Key, typename Value>
DictNode<Key,Value>* Dict<Key,Value>::deleteNode(const Key& k){  

    DictNode<Key,Value>* z = nullptr;
    DictNode<Key,Value>* x = nullptr;

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




template<typename Key, typename Value>
DictNode<Key,Value>* Dict<Key,Value>::iterativeSearch(DictNode<Key,Value>* x, const Key& k){    

    if (x == nullptr) return nullptr;
    if (x->key == k) return x;
    if (x->key < k){
        iterativeSearch(x->left, k);
    } 
    else{
        iterativeSearch(x->right, k);
    }

    
};



template<typename Key, typename Value>
void Dict<Key,Value>::release(DictNode<Key,Value>* x){
    
    if (x != nullptr){
        release(x->left);
        release(x->right);
        std::cout << "Deleted: " << x->key << "\n"; 
        x = nullptr;
    }
};




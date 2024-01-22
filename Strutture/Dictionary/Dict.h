#ifndef DICT_H
#define DICT_H

#include "DictNode.h"
#include <iostream>

template <typename Key, typename Value>
class Dict{

    private:   //dichiaro protected per usare root nelle funzioni == strunzat
        DictNode<Key, Value>* root;

    public:

        //constructors
        Dict(DictNode<Key,Value>* r = nullptr): root{r} {}
        ~Dict() {release(root);}

        //Traverse
        void preOrderTreeWalk(DictNode<Key,Value>* x);
        void preOrderTreeWalk() {preOrderTreeWalk(root);}
        void inOrderTreeWalk(DictNode<Key,Value>* x);
        void inOrderTreeWalk() {inOrderTreeWalk(root);} // stampa in ordine
        void postOrderTreeWalk(DictNode<Key,Value>* x);
        void postOrderTreeWalk() {postOrderTreeWalk(root);}


        //Accessors
        DictNode<Key,Value>* getRoot() {return root;}
        DictNode<Key,Value>* search(DictNode<Key,Value>* x, const Key& k);
        DictNode<Key,Value>* iterativeSearch(DictNode<Key,Value>* x, const Key& k);
        DictNode<Key,Value>* iterativeSearch(const Key& k) {search(root,k);}
        DictNode<Key,Value>* search(const Key& k) {search(root,k);}
        DictNode<Key,Value>* minimum(DictNode<Key,Value>* subroot);
        DictNode<Key,Value>* minimum() {minimum(root);}
        DictNode<Key,Value>* maximum(DictNode<Key,Value>* subroot);
        DictNode<Key,Value>* maximum() {maximum(root);}
        DictNode<Key,Value>* predecessor(const Key& k);
        DictNode<Key,Value>* successor(const Key& k);

        //Modifiers
        void insert(const Key& k, const Value& v);  //if return NULL, the key already exists
        void release(DictNode<Key,Value>* x);
        DictNode<Key,Value>* deleteNode(const Key& k);   // if return NULL, the key doesn't exist


};


#include "Dict.cpp"





#endif
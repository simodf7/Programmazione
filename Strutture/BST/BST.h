#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <iostream>

template <typename T>
class BST{

    private:   //dichiaro protected per usare root nelle funzioni == strunzat
        BSTNode<T>* root;

    public:

        //constructors
        BST(BSTNode<T>* r = nullptr): root{r} {}
        ~BST() {release(root);}

        //Traverse
        void preOrderTreeWalk(BSTNode<T>* x);
        void preOrderTreeWalk() {preOrderTreeWalk(root);}
        void inOrderTreeWalk(BSTNode<T>* x);
        void inOrderTreeWalk() {inOrderTreeWalk(root);} // stampa in ordine
        void postOrderTreeWalk(BSTNode<T>* x);
        void postOrderTreeWalk() {postOrderTreeWalk(root);}


        //Accessors
        BSTNode<T>* getRoot() {return root;}
        BSTNode<T>* search(BSTNode<T>* x, const T& k);
        BSTNode<T>* iterativeSearch(BSTNode<T>* x, const T& k);
        BSTNode<T>* iterativeSearch(const T& k) {search(root,k);}
        BSTNode<T>* search(const T& k) {search(root,k);}
        BSTNode<T>* minimum(BSTNode<T>* subroot);
        BSTNode<T>* minimum() {minimum(root);}
        BSTNode<T>* maximum(BSTNode<T>* subroot);
        BSTNode<T>* maximum() {maximum(root);}
        BSTNode<T>* predecessor(const T& k);
        BSTNode<T>* successor(const T& k);

        //Modifiers
        void insert(const T& k);  //if return NULL, the key already exists
        void recInsert(BSTNode<T>* x, const T& k);
        void recInsert(const T& k);
        void release(BSTNode<T>* x);
        BSTNode<T>* deleteNode(const T& k);   // if return NULL, the key doesn't exist


};


#include "BST.cpp"





#endif
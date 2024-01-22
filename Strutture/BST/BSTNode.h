#ifndef BSTNODE_H
#define BSTNODE_H


template <typename T> class BST;

template <typename T>
class BSTNode{

    private:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* parent;
        friend class BST<T>;

    public: 
        BSTNode(const T& k, BSTNode<T>* l = nullptr, BSTNode<T>* r = nullptr, BSTNode<T>* p = nullptr): key{k},
        left{l}, right{r}, parent{p} {}
        


};



#endif
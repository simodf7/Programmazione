#ifndef CNODE_H
#define CNODE_H

template <typename T> class CLinkedList;

template <typename T>
class CNode{

private:
    T elem;
    CNode<T>* next;
    friend class CLinkedList<T>;

// public:
//     const T& getElem() const {return elem;}

};

#endif 
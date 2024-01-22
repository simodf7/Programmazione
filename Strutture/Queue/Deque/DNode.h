#ifndef DNODE_H
#define DNODE_H

// nomino la classe LinkedList<NODETYPE> per poterla definire come friend
template<typename T> class DLinkedList;


template <typename T>
class DNode{
    private:
        T elem;
        DNode<T>* prev;
        DNode<T>* next;
        friend class  DLinkedList<T>;
    
};

#endif
#ifndef NODE_H
#define NODE_H

// nomino la classe LinkedList<NODETYPE> per poterla definire come friend
template<typename T> class LinkedList;


template <typename T>
class Node{
    private:
        T elem;
        Node<T>* next;
        friend class  LinkedList<T>;
    
};

#endif
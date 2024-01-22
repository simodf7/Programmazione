#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <string>
#include "DNode.h"

template <typename T>
class DLinkedList{

    protected:       // local utilities
        void add(DNode<T>* v, const T& e);  // insert new node before v
        void remove(DNode<T>* v); // remove node v
    private:
        DNode<T>* header;   // pointer to the head of the list
        DNode<T>* trailer;    // pointer to the tail of the list
    public:
        DLinkedList();   // default constructor
        ~DLinkedList();  // destructor
        DLinkedList(const DLinkedList&);// copy constructor
        bool isEmpty() const;     // is list empty?
        const T& front() const;   // get front element
        const T& back() const;  // get back element
        void addFront(const T& e);  // add to front of list
        void addBack(const T& e);   // add to back of list
        void removeFront();  // remove from front
        void removeBack();  // remove from back
        void removePari();
        void bubbleSort();
        int size() const;  // return number of element in the list
        //  int search(const T& e); // locate the node containing an element
        DLinkedList<T>& reverse();  // reverse a list
        std::string toString() const;
        //  DLinkedList<T>& deleteEl(int); // delete an element on the list
        DLinkedList<T>& operator=(const DLinkedList<T>&);
        //  T& operator[](int) const;
        void swap(); // swappa elementi di indice pari con quelli dispari
};


#include "DLinkedList.cpp"

#endif
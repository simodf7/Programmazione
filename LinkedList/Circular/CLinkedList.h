#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include <string>
#include "CNode.h"

template <typename T>
class CLinkedList{
    
    private:
        CNode<T>* cursor;   // cursor
    public:
        CLinkedList();   // default constructor
        ~CLinkedList();  // destructor
        CLinkedList(const CLinkedList& l); // copy constructor
        bool isEmpty() const;     // is list empty?
        const T& front() const;   // get front element
        const T& back() const;  // get back element
        void advance();   // advance cursor
        void add(const T& e); // add after cursor
        void remove();     // remove node after cursor
        // void addFront(const T& e);  // add to front of list
        // void addBack(const T& e);   // add to back of list
        // void removeFront();  // remove from front
        // void removeBack();  // remove from back
        int size() const;  // return number of element in the list
        //  int search(const T& e); // locate the node containing an element
        //  CLinkedList<T>& reverse();  // reverse a list
        std::string toString() const;
        //  CLinkedList<T>& deleteEl(int); // delete an element on the list
        CLinkedList<T>& operator=(const CLinkedList<T>&);
        void reverse();
        //  T& operator[](int) const;
        //CNode<T>* getCursor() const { return cursor;}
};


#include "CLinkedList.cpp"

#endif
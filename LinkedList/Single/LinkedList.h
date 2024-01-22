#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList{

    private:
        Node<T>* head;    // pointer to the head of the list
    public:
        LinkedList();   // default constructor
        ~LinkedList();  // destructor
        LinkedList(const LinkedList&);   // copy constructor
        bool isEmpty() const;   // is list empty?
        const T& front() const;  // get front element
        void addFront(const T& e);  // add to front of list
        void addBack(const T& e);  // add to back of list O(n) == not good
        void removeFront();  // remove from top of list   (you can use only three pointers)
        int size() const;  // return number of element in the list
        int search(const T& e); // locate the node containing an element
        LinkedList<T>& reverse();  // reverse a list
        std::string toString() const;
        LinkedList<T>& deleteEl(int); // delete an element on the list
        LinkedList<T>& operator=(const LinkedList<T>&);
        T& operator[](int) const;
};


#include "LinkedList.cpp"


#endif
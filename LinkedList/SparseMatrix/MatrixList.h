#ifndef MATRIXLIST_H
#define MATRIXLIST_H


#include "MatrixNode.h"

class MatrixList{
    private:
        MatrixNode* head;    // pointer to the head of the list
    public:
        MatrixList();   // default constructor
        ~MatrixList();  // destructor
        bool isEmpty() const;   // is list empty?
        int front() const;  // get front element
        void addFront(int e);  // add to front of list
        void remove();  // remove from top of list   (you can use only three pointers)
};
#endif
#ifndef LSTACK_H
#define LSTACK_H


#include "LinkedList.h"
#include <stdexcept>

template <typename T>
class LinkedStack{

    public:
        LinkedStack();
        int size() const;
        bool empty() const;
        const T& top();
        void push(const T&);
        void pop();

    private:
        LinkedList<T> s;  // linked list of elements
        int n;   // number of elements
};

#include "Lstack.cpp"

#endif
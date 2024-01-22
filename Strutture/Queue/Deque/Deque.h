#ifndef DEQUE_H
#define DEQUE_H

#include "DLinkedList.h"
#include <stdexcept>


template <typename T>
class Deque{

    private:
        DLinkedList<T> d;
        int n;   // counter;


    public:
        Deque();
        void insertFront(const T&);
        void insertBack(const T&);
        void eraseFront();
        void eraseBack();
        const T& front();
        const T& back();
        int size() const;
        bool empty();



};

#endif
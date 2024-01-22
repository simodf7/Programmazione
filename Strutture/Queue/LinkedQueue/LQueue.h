// Queue using Circular Linked List
#ifndef LQUEUE_H
#define LQUEUE_H

#include "CLinkedList.h"
#include <stdexcept>


template <typename T>
class LinkedQueue{

   private:    
        CLinkedList<T> c; // circular list of elements
        int n;  // number of elements

    public:
        LinkedQueue();
        int size() const; 
        bool empty() const;
        const T& front();
        void enqueue(const T&);
        void dequeue(); 


};

template<typename T>
LinkedQueue<T>::LinkedQueue(): c(), n{0} {}

template<typename T>
int LinkedQueue<T>::size() const{ return n;}

template<typename T>
bool LinkedQueue<T>::empty() const{ return n==0;}

template<typename T>
const T& LinkedQueue<T>::front(){ 
    if(empty()) {throw std::runtime_error("Queue is empty, you cannot get the front");}
    return c.front();
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& e){
    
    c.add(e);
    c.advance();
    n++;
    
}

template<typename T>
void LinkedQueue<T>::dequeue(){

    if(c.isEmpty()) {throw std::runtime_error("Queue is empty, nothing to remove");}
    
    c.remove();
    n--;


};


#endif
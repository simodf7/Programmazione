#include "Deque.h"

template<typename T>
Deque<T>::Deque(): d(), n{0}{
}

template<typename T>
void Deque<T>::insertFront(const T& e){
    d.addFront(e);
    n++;
}

template<typename T>
void Deque<T>::insertBack(const T&){
    d.addBack(e);
    n++;   
}

template<typename T>
void Deque<T>::eraseFront(){
    if(empty()) {throw std::runtime_error ("Deque is empty");}
    d.removeFront();
    n--;
}

template<typename T>
void Deque<T>::eraseBack(){
    if(empty()) {throw std::runtime_error ("Deque is empty");}
    d.removeBack();
    n--;
}

template<typename T>
const T& Deque<T>::front(){ return d.front();}

template<typename T>
const T& Deque<T>::back(){ return d.back();}

template<typename T>
int Deque<T>::size() const{ return n;} 

template<typename T>
bool Deque<T>::empty(){ return n==0;}

#include "LStack.h"

template <typename T>
LinkedStack<T>::LinkedStack(): n{0}, s(){

}

template <typename T>
int LinkedStack<T>::size() const { return n;}

template <typename T>
bool LinkedStack<T>::empty() const { return n == 0;}


template <typename T>
const T& LinkedStack<T>::top(){
    if(empty()) {throw std::runtime_error("Stack is empty");}
    return s.front();
}

template <typename T>
void LinkedStack<T>::push(const T& e){
    ++n;
    s.addFront(e);
}

template <typename T>
void LinkedStack<T>::pop(){
    --n;
    s.removeFront();
    
}

//Stack using array

#ifndef ASTACK_H
#define ASTACK_H

#include <stdexcept>
static int DEF_CAPACITY{10};  // default capacity


template <typename T>
class ArrayStack{

    static const int DEF_CAPACITY{10};  // default capacity

    public:
    ArrayStack(int = DEF_CAPACITY); //costruttore di default
    ~ArrayStack();
    void push(const T&);   // push element onto stack   
    void pop();   // pop element from stack
    int size() const;
    bool empty() const;
    const T& top() const;

    private:
    T* s;  // definisco un puntatore a T di nome array  (array of stack elements)
    int capacity; // la dimensione dell'array deve essere definita a priori  (capacity of stack)
    int t; // mi indica la posizione dell'ultimo elemento inserito (index of the stack)


};

template<typename T>
ArrayStack<T>::ArrayStack(int c): capacity{c}, t{-1} {
    s = new T[capacity];
}

template<typename T>
ArrayStack<T>::~ArrayStack(){
    delete s;
}

template<typename T>
void ArrayStack<T>::push(const T& e){
    if(size() == capacity) {throw std::runtime_error("Stack is full");}
    s[++t] = e;
}

template<typename T>
void ArrayStack<T>::pop(){
    if(empty()) {throw std::runtime_error("Stack is empty");}
    --t;
}

template<typename T>
int ArrayStack<T>::size() const{return t+1;}

template<typename T>
bool ArrayStack<T>::empty() const{return t<0;} // return t == -1

template<typename T>
const T& ArrayStack<T>::top() const{
    if(empty()) {throw std::runtime_error("Stack is empty");}    
    return s[t];
}


#endif
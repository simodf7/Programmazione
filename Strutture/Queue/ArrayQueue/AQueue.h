#ifndef AQUEUE_H
#define AQUEUE_H

#include <stdexcept>

template <typename T>
class ArrayQueue{
    
    static const int N{10};
    
    private:
        int n; // capacity of queue
        T* queue;
        int head;
        int tail;

    public:
        ArrayQueue();
        ~ArrayQueue();
        void enqueue(const T& e);
        void dequeue();
        int size();
        bool empty();
        const T& front();



};


template<typename T>
ArrayQueue<T>::ArrayQueue(): n{0}, head{0}, tail{0}{
    queue = new T[n];
}

template<typename T>
ArrayQueue<T>::~ArrayQueue(){
    delete [] queue;
}


template<typename T>
void ArrayQueue<T>::enqueue(const T& e){

    if (size() == N) {throw std::runtime_error("Queue is full");}
    queue[tail] = e;
    tail = (tail+1) % N;   // aggiungo un elemento e faccio avanzare la coda (resto N perche se supero torno a 0)
    n++;
}

template<typename T>
void ArrayQueue<T>::dequeue(){
    if(empty()) {throw std::runtime_error("Queue is empty");}
    head = (head+1)% N ; // faccio avanzare la testa
    n--;
}

template<typename T>
int ArrayQueue<T>::size(){return n;}

template<typename T>
bool ArrayQueue<T>::empty(){return n==0;}




template<typename T>
const T& ArrayQueue<T>::front(){
    if (empty()) {throw std::runtime_error("Queue is empty");}
    return queue[head];
};


#endif
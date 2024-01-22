#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap{

    private:
        T* A;
        int dim; 
        void swap(int,int);
        void heapify(int);
        void buildHeap();
    
    public:
       Heap(T*, int);
       ~Heap();
       void heapsort();
       const T& getArray();
    

};


#include "Heap.cpp"

#endif
#include "Heap.h"

template<typename T>
Heap<T>::Heap(T* array, int n): dim{n}{

    A = new T[dim];
    for(int i=0; i<dim-1; ++i){
        A[i] = array[i];
    }

    buildHeap();
}


template<typename T>
Heap<T>::~Heap(){
    delete[] A;
}


template<typename T>
void Heap<T>::heapify(int n){
    int largest;
    int l = 2*n + 1; //nodo figlio sx
    int r = 2*n + 2; // nodo figlio dx

    
    // vediamo se le chiavi sono piu grandi del nodo padre
    if(l<dim && A[l] > A[n]) {
        largest = l;
    }
    else largest = n;

    if (r<dim && A[r] > A[largest]){
        largest = r;
    }

    // se largest = n allora non devo fare nulla
    // altrimenti devo scambiare


    if (largest != n){
        swap(n, largest);
        heapify(largest);
    }

}



template<typename T>
void Heap<T>::buildHeap(){
    for(int i=(dim-1)/2; i>0; --i;){
        heapify(A, i);
    }
}

template<typename T>
void Heap<T>::swap(int x,int y){
    T temp = A[x];
    A[x] = A[y];
    A[y] = temp;
    
}


template<typename T>
void Heap<T>::heapsort(){
    for(int i=(dim-1)/2; i>0; --i){
        swap(i,0);
        --dim; 
        heapify(0);
    }
    
}





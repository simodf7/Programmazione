#include <sstream>
#include "DLinkedList.h"
#include "algorithm"

template<typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e){

    DNode<T>* u = new DNode<T>; 
    u->elem = e; 

    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

template<typename T>
void DLinkedList<T>::remove(DNode<T>* v){

    DNode<T>* p = v->prev;
    DNode<T>* c = v->next;

    p->next = c;  // unlink v from the list
    c->prev = p;

    delete v; 
}

template<typename T>
DLinkedList<T>::DLinkedList():{ 

    header = new DNode<T>;  // creation of sentinels node
    trailer = new DNode<T>;
    header->prev = nullptr;   // have them point each other
    header->next = trailer;
    trailer->prev = header;
    trailer->next = nullptr;
    
}

template<typename T>
DLinkedList<T>::~DLinkedList(){
    
    while(!isEmpty()) removeFront(); 
    delete header;
    delete trailer;

}

template<typename T>
bool DLinkedList<T>::isEmpty() const  {return header->next == trailer;}

template<typename T>
const T& DLinkedList<T>::front() const{ return header->next->elem;}

template<typename T>
const T& DLinkedList<T>::back() const{ return trailer->prev->elem;}


template<typename T>
void DLinkedList<T>::addFront(const T& e){
    add(header->next, e);
}

template<typename T>
void DLinkedList<T>::addBack(const T& e){
    add(trailer->prev, e);
}

template<typename T>
void DLinkedList<T>::removeFront(){
    remove(header->next);
}

template<typename T>
void DLinkedList<T>::removeBack(){
    remove(trailer->prev);
}

template<typename T>
void DLinkedList<T>::sort(){

    if(empty()) return;

    bool swapped{true};
    DNode<T>* cur;
    while(swapped){ //faccio un while fin quando non faccio piu swap
        swapped = false;
        //scorri la lista
        cur = header->next;
        while(cur->next != trailer){ // confronta ogni elemetno con il successivo fino alla fine
            if(cur->elem > cur->next->elem){
                std::swap(cur->elem, cur->next->elem);
                swapped = true;
            }
            cur = cur->next;
        }

    }

}

template<typename T>
std::string DLinkedList<T>::toString() const{\

    int i{0};   // counter
    std::ostringstream out;
    DNode<T>* u = header->next;

    while(u != trailer){
        out << "Node[" << i << "] = " << u->elem;
        u = u->next;
    }
}



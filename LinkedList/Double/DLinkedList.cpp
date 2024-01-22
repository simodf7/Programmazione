#include <sstream>
#include "DLinkedList.h"
#include "algorithm"
#include <iostream>

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
DLinkedList<T>::DLinkedList(){ 

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
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& l){

    if(this == &l) return *this;
    
    while(!isEmpty()) removeFront(); 

    DNode<T>* p = l.trailer->prev;
    while( p != l.header){
        addFront(p->elem);
        p = p->prev;
    }

}



template <typename T>
void DLinkedList<T>::swap(){                   
    
    DNode<T>* v = header->next->next;  // es nodo2
    DNode<T>* p = nullptr;

    if(size()%2==0){
        for(int i=0; i<size()/2; i++){
            p = v->prev;  // es nodo1
            T elem = v->elem;
            v->elem = p->elem;
            p->elem = elem;
            v=v->next->next;  // es nodo 4
        }
    }
    else if(size()%2!=0){
        for(int i=0; i<(size()-1)/2; i++){
                p = v->prev; 
                T elem= v->elem;
                v->elem=p->elem;
                p->elem=elem;
                v=v->next->next;
            }
    }



}


template<typename T>
DLinkedList<T>::DLinkedList(const DLinkedList& l){
    
    header = new DNode<T>;  // creation of sentinels node
    trailer = new DNode<T>;
    header->prev = nullptr;   // have them point each other
    header->next = trailer;
    trailer->prev = header;
    trailer->next = nullptr;
    
    DNode<T>* p = (l.trailer)->prev;
    while( p != l.header){
        addFront(p->elem);
        p = p->prev;
    }


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
    add(trailer, e);
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
void DLinkedList<T>::removePari(){

    int i{0};
    DNode<T>* cur = header->next;
    DNode<T>* s = nullptr;

    while(cur != trailer){
        s = cur->next;
        if(i %2 == 0){  
            remove(cur);
        }
        i++;
        cur = s;
    }

    
}



template<typename T>
int DLinkedList<T>::size() const{
    DNode<T>* p = header->next;
    int i{0};
    while(p !=trailer){
        i++;
        p = p->next;
    }

    return i;
}

template<typename T>
DLinkedList<T>& DLinkedList<T>::reverse(){

    DLinkedList<T>* s = new DLinkedList<T>; // temporary list
    T m;
    while(!(isEmpty())){ // reverse list into S
        m = front();
        //std::cout << "Debug primo while: " << m << "\n";
        removeFront();
        // s.addFront(m);
        s->addFront(m);
    }
    while(!(s->isEmpty())){ //copy S back to list
        m = s->front();
        //std::cout << "Debug secondo while: " << m << "\n";
        s->removeFront();
        //std::cout << "a";
        addBack(m);
        //std::cout << "b";
    }

    delete s;
    return *this;
    
}



template<typename T>
void DLinkedList<T>::bubbleSort(){ // bubble sort

    if(isEmpty()) return;

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
std::string DLinkedList<T>::toString() const{

    int i{0};   // counter
    std::ostringstream out;
    DNode<T>* u = header->next;

    while(u != trailer){
        out << "Node[" << i << "] = " << u->elem << "\n";
        u = u->next;
        i++;
    }

    return out.str();
}



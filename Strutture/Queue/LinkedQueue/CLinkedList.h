#ifndef CLinkedList_H
#define CLinkedList_H

#include <string>
#include "CNode.h"
#include <sstream>

template <typename T>
class CLinkedList{
    
    private:
        CNode<T>* cursor;   // cursor
    public:
        CLinkedList();   // default constructor
        ~CLinkedList();  // destructor
        bool empty() const;     // is list empty?
        const T& front() const;   // get front element
        const T& back() const;  // get back element
        void advance();   // advance cursor
        void add(const T&); // add after cursor
        void remove();     // remove node after cursor
        std::string toString();
};


template <typename T>
CLinkedList<T>::CLinkedList()
    : cursor{nullptr}{    
}

template <typename T>
CLinkedList<T>::~CLinkedList(){while(!empty()) remove(); }

template <typename T>
bool CLinkedList<T>::empty() const{return cursor == nullptr; }

template <typename T>
const T& CLinkedList<T>::back() const{return cursor->elem; }

template <typename T>
const T& CLinkedList<T>::front() const{return cursor->next->elem; }

template <typename T>
void CLinkedList<T>::advance(){cursor = cursor->next; }

template <typename T>
void CLinkedList<T>::add(const T& e){
    CNode<T> *v =new CNode<T>;
    v->elem = e;
    if(cursor == nullptr){
        v->next = v;
        cursor = v;
    } else{
        v->next = cursor->next;
        cursor->next = v;
    }
}

template <typename T>
void CLinkedList<T>::remove(){
    CNode<T> *old = cursor->next;
    if(old == cursor){
        cursor = nullptr;
    } else{
        cursor->next = old->next;
    }
    delete old;
}

template <typename T>
std::string CLinkedList<T>::toString(){
    std::ostringstream out;
    CNode<T> *u =cursor;
    out <<"Cursor --> ";
    out <<u->elem <<" --> ";
    u = u->next;
    while(u != cursor){
        out <<u->elem <<" --> ";
        u = u->next; 
    }
    out <<"Cursor";
    return out.str();
};


#endif
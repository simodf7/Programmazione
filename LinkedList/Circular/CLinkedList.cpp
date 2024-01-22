#include "CLinkedList.h"
#include <sstream>



template<typename T>
CLinkedList<T>::CLinkedList(): cursor{nullptr}{}

template<typename T>
CLinkedList<T>::~CLinkedList(){
    while(!isEmpty()) remove();
}

template<typename T>
CLinkedList<T>::CLinkedList(const CLinkedList& c){

    //cursor = nullptr;
    // CNode<T>* p = l.cursor;
    // add(p->elem);
    

    // for(int j=0; j<l.size()-1; j++){
    //     for(int i=0; i<l.size()-j-1 ; i++){
    //         p = p->next;
    //     }
    //     add(p->elem);
    //     p = l.cursor;
    // }


    cursor=nullptr;
    CNode<T>* p = c.cursor->next;
    for(int i=0 ; i< c.size(); i++){
        add(p->elem);
        p=p->next;
        advance();
    }
}







template<typename T>
CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList& l){

    if(this == &l) return *this;
    
    while(!isEmpty()) remove(); 

    cursor = nullptr;
    CNode<T>* p = l.cursor->next;
    for(int i=0 ; i<l.size(); i++){
        add(p->elem);
        p=p->next;
        advance();
    }


}

template<typename T>
void CLinkedList<T>::reverse(){

    if (cursor == nullptr)
    {
        std::cout << "Empty linked list";
        return;
    }


    if(size()<2)return;
    CNode<T>* value = cursor;
    advance();
    CNode<T>* prev{cursor};
    CNode<T>* next{nullptr};
    CNode<T>* current{cursor->next};

    while(current != cursor){
        next = current->next;
        //std::cout << "debug: "  << next->elem;
        current->next = prev;
        prev = current;
        current = next;
    }

    cursor->next = value;


}




template<typename T>
bool CLinkedList<T>::isEmpty() const { return cursor == nullptr;}

template<typename T>
const T& CLinkedList<T>::front() const { return cursor->next->elem;}

template<typename T>
const T& CLinkedList<T>::back() const { return cursor->elem;}


template<typename T>
int CLinkedList<T>::size() const {

    int c{0};
    CNode<T>* p = cursor->next;
    while(true){
        if(p == cursor){
            c++;
            break;
        }
        //std::cout << "/Debug: c: " << c <<"\n"; 
        p = p->next;
        c++;
    }
    

    return c;
}

template<typename T>
void CLinkedList<T>::advance() { 
    cursor = cursor->next;
}

template<typename T>
void CLinkedList<T>::add(const T& e){

    CNode<T>* v = new CNode<T>;
    v->elem = e;
    if(cursor == nullptr){  // list is empty
        v->next = v;    // v has to point on itself
        cursor = v;     // cursor point to v
    }
    else{
        v->next = cursor->next; // v->next has to point to what cursor->next pointed before
        cursor->next = v;    // link in v after cursor
    }
}

template<typename T>
void CLinkedList<T>::remove(){

    CNode<T>* old = cursor->next;  // old = node to remove
    if(old == cursor){   // list is only one node
        cursor = nullptr;
    }
    else { cursor->next = old->next;}
    
    delete old;

}

template<typename T>
std::string CLinkedList<T>::toString() const{
    std::ostringstream out;
    int i{0};
    CNode<T>* u = cursor->next;

    while(true){
        if(u == cursor) {
            out << "Node[" << i << "] = " << u->elem << "\n";
            break;
        }
        else{
            out << "Node[" << i << "] = " << u->elem << "\n\n"; 
            u = u->next;
            i++;
        } 
    }

    return out.str();
    
}

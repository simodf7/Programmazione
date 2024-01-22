#include "MatrixList.h"
#include <stdexcept>

MatrixList::MatrixList(){
    this->head = nullptr; 
}

MatrixList::~MatrixList(){
    while(!isEmpty()){
        remove();
    }
}


bool MatrixList::isEmpty() const{ return head == nullptr;}
int MatrixList::front() const{ return head->next->elem;}

void MatrixList::addFront(int e){
    MatrixNode* v = new MatrixNode;  
    v->elem = e;  
    v->next = head;  
    head = v;  
}

void MatrixList::remove(){
 if(isEmpty()){ throw std::runtime_error("List is already empty");}
    MatrixNode* old = head;  // old = pointer to old head
    head = old->next; // head = pointer to node pointed by previous head
    delete old;  // we delete the old pointer
   
}

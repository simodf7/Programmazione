#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList(){
    this->head = nullptr;   // default
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    while(!isEmpty()){
        removeFront();
    }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& l){

    this->head = nullptr;
    for (int i = (l.size()-1); i >=0; i--){
        addFront(l[i]);
    } 

    
}


template<typename T>
bool LinkedList<T>::isEmpty() const{ return head == nullptr;}

template<typename T>
const T& LinkedList<T>::front() const{ return head->elem;}

template<typename T>
void LinkedList<T>::addFront(const T& e){
    
    Node<T>* v = new Node<T>;  // creat new node
    v->elem = e;  // store data
    v->next = head;   // tramite puntatore impongo che il puntatore a nodo punti al vecchio head della lista
    head = v;  // impongo che la nuova head sia v

}

template<typename T>
void LinkedList<T>::addBack(const T& e){

    Node<T>* v = head;

    while(v->next != nullptr){
        //std::cout << v->elem << "\n";
        v = v->next;
    }
   
    

    Node<T>* p = new Node<T>;
    v->next = p;
    p->elem = e;
    p->next = nullptr;

    
}

template<typename T>
void LinkedList<T>::removeFront()
{
    if(isEmpty()){ throw std::runtime_error("List is already empty");}
    Node<T>* old = head;  // old = pointer to old head
    head = old->next; // head = pointer to node pointed by previous head
    delete old;  // we delete the old pointer
    
}

template<typename T>
int LinkedList<T>::size() const{    
   
   if(isEmpty()) {return 0;}
   
   int count{1};
   Node<T>* n = head;
   while(n->next != nullptr){
        n = n->next;
        ++count;
    }
    
    return count;
    
}

template<typename T>
int LinkedList<T>::search(const T& e){

    bool found = false;
    if(isEmpty()){throw std::runtime_error("List is empty: you cannot search in an empty list");}
    int count{1};
    Node<T>* n = head;
    while(n->next != nullptr){
        if (n->elem == e){found = true; }
        else {
            n = n->next;
            ++count;
        }
    }

    if (found == true) { return count; }    // the first node is counted as 1 and not 0
    else std::cout << "Element not found in the list \n";


}

template<typename T>
LinkedList<T>& LinkedList<T>::reverse(){
    
    if(isEmpty()){throw std::runtime_error ("List is empty: you cannot reverse an empty list");}
    if(size()==1) {return *this;}

    Node<T>* p = nullptr; // previous
    Node<T>* c = head;  // current
    Node<T>* n = nullptr;  // next

    while(c != nullptr){
        n = c->next;
        c->next = p; 
        p = c;
        c = n;
    } 

    head = p;
    delete c;
    delete n;
    return *this;


}

template<typename T>
std::string LinkedList<T>::toString() const{

    
    Node<T>* n = head;
    std::ostringstream output;

    for(int i=0; i<size(); ++i){
        output << "Node[" << i << "] = " << n->elem << "\n";
        n = n->next;
    }
    return output.str();
}

template<typename T>
LinkedList<T>& LinkedList<T>::deleteEl(int n){

    if(isEmpty()){throw std::runtime_error("List is empty");}
    


    Node<T>* p = head; // previous
    Node<T>* c = head->next;  // current

    for(int i=0; i<n-1; i++){
        p = p->next;
        c = c->next;
    }

    p->next = c->next;
    delete c; 

    return *this;
    

}




template<typename T>
LinkedList<T>&  LinkedList<T>::operator=(const LinkedList<T>& l){
   
    if(this==&l) {return *this;}

    while(!isEmpty()) removeFront();

    for (int i = (l.size()-1); i >=0; i--){
        addFront(l[i]);
    } 

    return *this;
}





template<typename T>
T& LinkedList<T>::operator[](int i) const{
    
    if (i > size()) {throw std::out_of_range("You requested an element of a non existing node");}
    
    Node<T>* n = head;

    for(int j=0; j<i; ++j){
        n = n->next;
    }

    return n->elem;
}

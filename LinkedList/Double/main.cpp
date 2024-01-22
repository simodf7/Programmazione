#include "DLinkedList.h"
#include <iostream>


int main(){

    DLinkedList<int> t;
    t.addFront(4);
    t.addFront(8);
    t.addFront(12);
    t.addBack(56);
    std::cout << t.toString() << "\n";

    // DLinkedList<int> m(t);
    // std::cout << m.toString() << "\n";

    // t.reverse().bubbleSort();
    t.removePari();
    std::cout << t.toString() << "\n";
}
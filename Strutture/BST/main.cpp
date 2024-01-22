#include "BST.h"


int main(){

    BST<int> t;
    // t.insert(8);
    // t.insert(12);
    // t.insert(4);
    t.insert(7);
    t.insert(12);
    t.insert(8);
    //std::cout << t.search(12) << "\n";
    std::cout << t.iterativeSearch(12) << "\n";
    //std::cout << t.predecessor(12) << "\n";
   // std::cout << t.successor(8) << "\n";

    //t.postOrderTreeWalk();
    //t.inOrderTreeWalk();
   // t.deleteNode(4);
    //t.inOrderTreeWalk();
}
#include <iostream>
#include "CLinkedList.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    CLinkedList<int> I;
    I.add(5);
    I.add(4);
    I.add(3);
    I.add(2);
    I.add(1);
    //cout << I.getCursor()->getElem() << "\n";
    cout << "Lista non copiata\n";
    cout << I.toString() << "\n";
   I.reverse();
    //cout << I.size();
    // cout << "Lista copiata\n";
    // CLinkedList<int> M{I};
    // cout << M.toString() << "\n";
    // cout << I.front() << endl;
    // I.remove();
   cout << I.toString() << "\n";



    return 0;
}
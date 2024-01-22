#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    LinkedList<int> I;
    I.addFront(10);
    I.addFront(14);
    I.addBack(8);
    I.addBack(9);
    I.addFront(7);
    cout << I.toString() << "\n";
    //  cout << I.front() << endl;

    //LinkedList<int> R(I);
    //R = I;
    // cout << "9";
    //cout << R.toString() << "\n";
    // I.removeFront();
    // cout << I.toString() << "\n";
    // cout << I.front() << endl;
    // // creo uno scope
    // {
    //     LinkedList<string> S;
    //     S.addFront("ASD");
    //     S.addFront("QWE");
    //     S.addFront("sdfsd");
    //     cout << S.front() << endl << "Size: " << S.size() << endl;
    //     cout << S[1] << endl;
    //     cout << S.toString() << endl;
    //     S.reverse();
    //     cout << S.toString() << endl;
    //     S.deleteEl(1);
    //     cout << S.toString() << endl;
    //  }
    // // uscito dallo scope, S dovrebbe venire eliminata



    return 0;
}
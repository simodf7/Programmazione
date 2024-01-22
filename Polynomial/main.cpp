// main.cpp
#include <iostream>
#include "Polynomial.h"

using std::cout;
using std::endl;

int main() {
   double c[] = {1, 2.5, 4, 3.2};
   Polynomial p1{c, 4};
   cout << "p1 = " << p1 << endl;
   Polynomial p2 = p1;
   cout << "p1 " << ((p1 == p2) ? "=" : "!=") << " p2" << endl;
   Polynomial p3;
   cout << "p1 " << ((p1 == p3) ? "=" : "!=") << " p3" << endl;
   Polynomial p4(4);
   cout << "deg(p1) = " << p1.degree() << endl;
   cout << "deg(p3) = " << p3.degree() << endl;
   p1.print();
   cout << endl;
   p1 += p4;
   cout << "p1 = " << p1 << endl;
   p1 *= 2;
   cout << "p1 = " << p1 << endl;
   Polynomial p5 = p1 * 3;
   cout << "p5 = " << p5 << endl;
   Polynomial p6 = 3 * p1;
   cout << "p5 " << ((p5 == p6) ? "=" : "!=") << " p6" << endl;


   double a[] = {2,2,1,1};
   double b[] = {1,1,1};

   Polynomial p7{a,4};
   Polynomial p8{b,3};
   

   Polynomial p9 = p7 * p8;
   cout << "(" << p7 << ") * (" << p8 << ") = " << p9;

    // double a[] = {1,1,2};
    // double b[] = {1,1};

    // Polynomial pa(a, 3);
    // Polynomial pb(b, 2);

    // Polynomial pc = pa * pb;

    // cout << "( " << pa << " ) ( " << pb << " ) =" << endl;
    // cout << "= " << pc << endl;

    return 0;
}
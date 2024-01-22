#include <iostream>
#include "Complex.h"

using std::cout;

int main(){

    Complex c1(2,5);
    Complex c2(5,2);

    cout << c1 << "\n";
    cout << c2 << "\n";
    cout << "Sum of c1 and c2: " << c1+c2 << "\n";
    cout << "Difference of c1 and c2: " << c1-c2 << "\n";
    cout << "Product of c1 and c2: " << c1*c2 << "\n";
    cout << "Division of c1 and c2: " << c1/c2 << "\n";


    return 0;
}
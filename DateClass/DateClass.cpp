#include <iostream>
#include "Date.h"
using std::cout;
using std::endl;

int main (){
    cout << endl;
    Date date1(21,32,123);
    Date date2(4,5,2019);
    date1.displayDate();
    cout << endl;
    date2.displayDate();
}


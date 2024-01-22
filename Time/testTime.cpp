#include <iostream>
#include <stdexcept>
#include <string>
#include "time.h"

using std::cout;
using std::string;
using std::invalid_argument;
using std::cerr;

void displayTime(const string &, const Time &);


int main(){

    Time t1;
    Time t2{2}; 
    Time t3{21,34};
    Time t4{12,35,24}; 

    displayTime("t1: all arguments defaulted", t1);
    displayTime("t2: hour specified; minute and second defaulted", t2);
    displayTime("t3: hour and minute specified; second defaulted", t3);
    displayTime("t4: hour, minute and second specified", t4);


    try {
        Time t5{27,74,99};
    }
    catch (invalid_argument &e){
        cerr << "Exception while initializing t5: " << e.what(); 
    }


}



void displayTime(const string &message, const Time &time){
    cout << message << "\nUniversal time: " << time.toUniversalString() 
        << "\nStandard Time: " << time.toStandardString() << "\n\n" ; 

}
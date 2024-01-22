#include <iostream>
#include <string>
#include "Heart.h"
using std::cout;
using std::endl;


int main (){
    HeartRates p1("Simone", "Di Fraia", 2001);
    HeartRates p2("Maria", "Mirabella", 1947);
    HeartRates p3("Angelo", "Paone", 1968);

    cout << endl;
    
    cout << "Person Name: " << p1.getfirstName() 
        << "\nPerson LastName: " << p1.getlastName()
        << "\nDate of Birth: " <<  p1.getYear() 
        << "\nAge: " << p1.provideAge() 
        << "\nMaximum Heart Rate: " << p1.maxHeartRate() << endl;
        p1.targetHeartRate();

    cout << endl;

    cout << "Person Name: " << p2.getfirstName() 
        << "\nPerson LastName: " << p2.getlastName()
        << "\nDate of Birth: " <<  p2.getYear() 
        << "\nAge: " << p2.provideAge() 
        << "\nMaximum Heart Rate: " << p2.maxHeartRate() << endl;
        p2.targetHeartRate();

    cout << endl;

}
#include <iostream>
#include <sstream>
#include <string>
#include "Date.h"
#include "Employee.h"


Employee::Employee(const std::string &fN, const std::string &lN, double s)
    : firstName{fN},
    lastName{lN},
    // birthDate{dB},
    // hireDate{dH},
    salary{s}
    {
        std::cout << "Employee object constructor: " << firstName << " " << lastName << "\n"; 
    }


std::string Employee::tostring() const{
    std::ostringstream output; 
    output << lastName << ", " << firstName <<  ", " << getSalary() << "\n";
    return output.str();
}


Employee::~Employee(){
    std::cout << "Employee object deconstructor: " << lastName << ", " << firstName << "\n";
}
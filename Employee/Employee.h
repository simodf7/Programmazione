#include <string>
//#include "Date.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee {

    public: 
        Employee (const std::string &, const std::string &, double);   // Constructor
        std::string tostring() const;
        double getSalary() const {return salary;}
        ~Employee(); // Destructor

    private:
        std::string firstName;
        std::string lastName;
        // Date birthDate;
        // Date hireDate;
        double salary;
};


#endif
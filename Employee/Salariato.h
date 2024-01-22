#include <iostream>
#include <string>
#include "Employee.h"

#ifndef SALARIATO_H
#define SALARIATO_H

class Salariato : public Employee{
  
    public:
    Salariato (std :: string , std :: string, double , unsigned int);
    ~Salariato()= default;

    void setSalario(double);
    double getSalario() const {return salario;}

    void setAggiunta(double);
    double getAggiunta() const {return aggiunta;}


    void guadagno (unsigned int) ;
    std :: string toString() ;


    private:
    double salario; //salario settimanale
    double aggiunta; 
};
#endif
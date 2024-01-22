#include <iostream>
#include "Salariato.h"
#include "Employee.h"
#include <sstream>

Salariato :: Salariato(std :: string n , std :: string c, double s, unsigned int h)
: Employee(n,c,s){ 
    
    setSalario(s);

}

void Salariato :: setSalario(double s){

    if (s<0){
    std::cout <<"\n out of range ";
    }

    salario=s;

}



void Salariato :: guadagno (unsigned int h) {


    if (h>8){
        setAggiunta((salario/5.00));
    }

}

void Salariato :: setAggiunta(double a){

    aggiunta = a;
}



std :: string Salariato :: toString(){

    std :: ostringstream output;
    output << "\n" <<Employee::tostring() << " " << Salariato::getSalario()+Salariato::getAggiunta();
    return output.str(); 

}
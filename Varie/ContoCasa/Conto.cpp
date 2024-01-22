#include "Conto.h"
#include <stdexcept>
#include <sstream>

Conto::Conto(float b){
    setBalance(b);
}

void Conto::deposit(float c){
    if(c>=0){
        balance += c;     
    }
    else {throw std::runtime_error("You can add only a positive number");}
}

void Conto::withdraw(float d){
    if(d>=0){
        balance -= d;     
    }
    else {throw std::runtime_error("You can subtract only a positive number");}
}

void Conto::setBalance(float balance){
    this->balance = balance;
}

float Conto::getBalance() const { return balance;}

std::string Conto::toStringDeposit(float c) const{
    std::ostringstream out;
    out << "Transaction: +" << c << "€ " ; 
    return out.str(); 
}


std::string Conto::toStringWithdraw(float d) const{
    std::ostringstream out;
    out << "Transaction: -" << d << "€ " ; 
    return out.str(); 
}

std::string Conto::toString() const{
    std::ostringstream out;
    out << "Balance: " << getBalance() << "€ ";
    return out.str();
}

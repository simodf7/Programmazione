#include "Account.h"
#include <iostream>
#include <exception>
using std::invalid_argument;

Account::Account(double sal){
    setBalance(sal);
}

void Account::setBalance(double sal){
    if(sal>=0){
        balance = sal;
    }
    else
        throw invalid_argument("Il saldo deve essere positivo");
}

double Account::getBalance() const {return balance;}

void Account::credit(double deposito){
    if(deposito>0){
        balance += deposito;
    }
    else
        throw invalid_argument("Il deposito deve essere maggiore di 0");
}

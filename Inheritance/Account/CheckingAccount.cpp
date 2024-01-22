#include "CheckingAccount.h"
#include <iostream>
#include <exception>
using std::invalid_argument;

CheckingAccount::CheckingAccount(double initial, double atm): Account(initial), totalFee{0.0}, atmFee{atm}
{};

void CheckingAccount::setAtmFee(double atm){
    if(atm>=0){
        atmFee = atm;
    }
    else
        throw invalid_argument("La commissione per il prelievo deve essere positiva");
}


void CheckingAccount::setTotalFee(double fee){
    totalFee = fee;
}

double CheckingAccount::getAtmFee() const {return atmFee;}
double CheckingAccount::getTotalFee() const {return totalFee;}


void CheckingAccount::cashWithdrawal(double pre){
    double prTot = pre + atmFee + totalFee;
    if(pre>0 && prTot<=getBalance()){
        double nuovoSaldo = getBalance() - prTot;
        setBalance(nuovoSaldo);   
    }
    else
        throw invalid_argument("Non puoi avere un saldo negtivo");
}


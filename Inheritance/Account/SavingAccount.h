#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"


class SavingAccount: public Account{

    SavingAccount(double initial, double rate) : Account(initial), annualRate{rate} {};  // constructor

    double totalAfterYears(int years) const;
 

private:
    double annualRate;

};





#endif
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount: public Account{

public:
    CheckingAccount(double,double);
    virtual ~CheckingAccount() = default;

    //funzioni set e get
    void setAtmFee(double);
    void setTotalFee(double);
    double getAtmFee() const;
    double getTotalFee() const;

    //overriding
    void cashWithdrawal(double);


private:
    double atmFee;
    double totalFee;


};


#endif
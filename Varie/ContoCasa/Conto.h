#ifndef CONTO_H
#define CONTO_H

#include <string>

class Conto{
   
public:
    Conto(float = 0.0);
    void deposit(float);
    void withdraw(float);
    void setBalance(float);
    float getBalance() const;
    std::string toStringDeposit(float) const;
    std::string toStringWithdraw(float) const;
    std::string toString() const;


private:
    float balance; // data member with default initial value
}; // end class Account




#endif
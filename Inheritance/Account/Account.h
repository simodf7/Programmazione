#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{

public:
    explicit Account(double=0.0);
    virtual ~Account() = default;
    //funzioni get e set
    void setBalance(double);
    double getBalance() const;
    //prelievo e deposito
    virtual void debit(double) =0; //prelievo
    void credit(double);

private:
    double balance;

};

#endif
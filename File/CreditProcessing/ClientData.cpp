#include "ClientData.h"
#include <stdexcept>


ClientData::ClientData(int a, const std::string& fN , const std::string& lN, double b): balance{b}
{
    setAccountNumber(a);
    setFirstName(fN);
    setLastName(lN);
}


void ClientData::setLastName(const std::string& lN)
{
    size_t lenght{lN.length()};
    lenght = (lenght < LAST_NAME_LENGHT) ? lenght : (LAST_NAME_LENGHT-1);
    lN.copy(lastName, lenght);
    lastName[lenght] = '\0';
    
}

void ClientData::setFirstName(const std::string & fN) 
{
    size_t length = fN.length();
    length = (length < FIRST_NAME_LENGHT) ? length : (FIRST_NAME_LENGHT-1);
    fN.copy(firstName, length);
    firstName[length] = '\0';
    
}

void ClientData::setAccountNumber(int accountNumber)
{
    if (accountNumber >=0 && accountNumber < 100)
        this->accountNumber = accountNumber;
    else 
        throw std::invalid_argument("Out of Range: Account number must be between 1 and 100");
    
}

void ClientData::setBalance(double balance)
{
    this->balance = balance;
}

int ClientData::getAccountNumber() const {return accountNumber;}
std::string ClientData::getLastName() const {return lastName;}
std::string ClientData::getFirstName() const {return firstName;}
double ClientData::getBalance() const {return balance;}

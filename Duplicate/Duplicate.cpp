#include <iostream>
#include <string>
#include "Account.h"
using std::cout;
using std::endl;

void displayAccount(Account a);

int main (){
    Account account1("Carola", 9000);
    Account account2("Michele", 0);
    displayAccount(account1);
    displayAccount(account2);
    return 0;
};


void displayAccount(Account a){
    cout << "Name: " << a.getName() << endl;
    cout << "Balance: " << a.getBalance() << endl;
}
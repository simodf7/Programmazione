#include <iostream>
#include <string>

class Account {
public: 

    Account (std::string n, int b)
        : name{n}, balance{b} {
        }

    

    void setName(std:: string n) {
        name = n;
    }
 
    std::string getName() const {
        return name;
    }
    
    void setBalance(int b) {
        if (b >= 0){
            balance = b;
        }
        else std::cout << "Balance must be a positive number" << std::endl; 
    }

    int getBalance() const {
        return balance;
    }



private:
    std::string name;
    int balance;
};
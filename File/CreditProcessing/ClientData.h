#ifndef CLIENTDATA_H_
#define CLIENTDATA_H_

#define LAST_NAME_LENGHT 15
#define FIRST_NAME_LENGHT 10

#include <string>

class ClientData {

 private:

   int accountNumber;
   char firstName[FIRST_NAME_LENGHT];
   char lastName[LAST_NAME_LENGHT];
   double balance;

 public:

  // constructors

   ClientData(int = 0,const std::string& = "",const std::string& = "",double = 0.0);
   void setFirstName(const std::string &);
   void setLastName(const std::string &);
   void setAccountNumber(int );
   void setBalance(double);
   int getAccountNumber() const;
   std::string getLastName() const;
   std::string getFirstName() const;
   double getBalance() const;

};

#endif //CREDITPROCESSINGPROGRAM__CLIENTDATA_H_
#ifndef BORROW_H
#define BORROW_H

#include "Book.h"
#include "Date\Date.h"




class Borrow : public Book{

public:
    Borrow( const Book& book=Book(), Date dateofB=Date());
    Borrow(const Book& , Date, Date);
    void print()const  override;
    const Date& getDateofBorrow() const;
    const Date& getDateofRestituion() const;



private:
    Date dateOfBorrow;
    Date dateOfRestituion;


};

#endif
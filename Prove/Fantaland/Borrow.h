#ifndef BORROW_H
#define BORROW_H

#include "Book.h"
#include "Date.h"
#include <iostream>

class Borrow: public Book{

    private:
        //Book borrowedBook;
        Date borrowDate;
        Date resDate;

    public:
        Borrow(const Book& b, const Date& d):Book(b), borrowDate(d), resDate{d+30} {}
       // Borrow(const Book& b, const Date& d): borrowedBook{b}, borrowDate(d), resDate{d+30} {}
       // Book getBook() const {return borrowedBook;}
        Date getResDate() const {return resDate;}
        //float getValue() const {return borrowedBook.getValue();}
        void print() {
            Book::print();

            std::cout<< " Date of borrow: " << borrowDate << "\n";
            std::cout<< " Date of Restituion: " << resDate << "\n";
        }
        




};



#endif
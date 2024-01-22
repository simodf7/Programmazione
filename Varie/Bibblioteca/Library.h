#ifndef LIBRARY_H
#define LIBRARY_H

#include "Borrow.h"
#include <list>
#include <vector>


class Library
{
public:
    Library(std::vector<Book> v={});
    void BorrowBook(int  , Date datOfB );  // prende un libro , creare nodo per la lista
    double valueExpired(const Date &) ;
    void print()const;
    double returnBook(int);

private:
    std::vector<Book> books;
    std::list<Borrow> listofBorrow;  // riempimento in modo ordinato 
protected:
    void inserOrder( const Borrow&);    

};

#endif
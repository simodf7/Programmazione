#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <list>
#include "Book.h"
#include "Borrow.h"

class Library{

    private:

        std::vector<Book> bib;
        std::list<Borrow> loan;

    public:
        Library(): bib{}, loan{} {}
        void insertBook(Book&);
        void borrow(const Book&, const Date&);
        void valueExpired(Date&);
        void printBooks();
        void printBorrows();
        void returnBook(const Book&,Date&);






};

#endif
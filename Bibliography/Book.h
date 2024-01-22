#ifndef BOOK_H
#define BOOK_H


#include "Publication.h"

class Book: public Publication {

public: 

    static int nBooks; // Book counter
    Book(std::string, std::vector<std::string>, int, std::string, int);
    ~Book();

    // member fucntions
    std::string toString();


    // set Functions
    Book& setPubHouse(std::string);
    Book& setIsbn(int);

    // get Functions 
    std::string getPubHouse() const;
    int getIsbn() const;

private: 
    std::string pubHouse;
    int isbn;

};


#endif
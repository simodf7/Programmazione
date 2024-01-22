#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
class Book
{
public:
    Book( int b_id= 0 , std::string tt="", std::vector<std::string> au={}, int yy=2000,
            std::string posiz="",double val=0.0 );
    bool operator<(const Book&)const;
    int getID() const;
    double getValue()const {return value;}
    virtual void print() const;

 private:
    int book_id;
    std::string title;
    std::vector<std::string> authors;
    int year;
    std::string position;
    double value;
    

};

#endif
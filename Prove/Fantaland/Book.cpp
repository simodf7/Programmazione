#include "Book.h"
#include <iostream>

Book::Book(int i, std::vector<std::string> a, const std::string& t, int y, const std::string& p, float v):book_id{i},
authors{a}, title{t}, year{y}, position{p}, value{v} {}


bool Book::operator<(const Book& b){

    if (authors < b.getAuthors()){return true;}
    else if(authors == b.getAuthors()){ return (year < b.getYear());}
    else{return false;}
    
}


void Book::print() const{

    std::cout << book_id << ": ";

    for (auto i : authors){
        std::cout << i << ", ";
    }    

    std:: cout << title
        << "(" << year << ")" << "(" << position << ") " << value << "$";

    std::cout << "\n";

}
#include "Book.h"
#include <sstream>

Book::Book(std::string title, std::vector<std::string> authors, int year, std::string pubHouse, int isbn):
Publication(title,authors, year){

    this->pubHouse = pubHouse;
    this->isbn = isbn;
    ++nBooks;
}


Book::~Book(){
    --nBooks;
}

Book& Book::setPubHouse(std::string p){
    pubHouse = p;
    return *this;

}

Book& Book::setIsbn(int i){
    isbn = i;
    return *this;
}



std::string Book::getPubHouse() const{
    return pubHouse;
}

int Book::getIsbn() const{
    return isbn;
}



std::string Book::toString(){

    std::ostringstream out;
    out << Publication::toString() << " " << isbn << " " << pubHouse << ".";
    return out.str();

}


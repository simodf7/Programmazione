#include "Publication.h"
#include <sstream>


Publication::Publication(std::string title,std::vector<std::string> authors, int year) {
    this->title = title;
    this->authors = authors;
    this->year = year;
    nGenPub++;
}


Publication::~Publication(){
    --nGenPub;
}

Publication& Publication::setTitle(std::string title){
    this->title = title;
    return *this;
}

Publication& Publication::setAuthors(const std::vector<std::string>& authors){
    this->authors = authors;
    return *this;
}

Publication& Publication::setYear(int year){
    this->year = year;
    return *this;
}




std::string Publication::getTitle() const{
    return title;
}


const std::vector<std::string>& Publication::getAuthors(){
    return authors;
}

int Publication::getYear() const{
    return year;
}



std::string Publication::toString(){

    std::ostringstream out;
    out << "-\t";
    for(int i=0;  i<authors.size(); ++i){
        out << authors[i];
        out << ((i==authors.size()-1)?" ":", ");
    }
    out << title << " "  << "(" << year << ") ";

    return out.str();
}




bool Publication::operator<(const Publication& p){

    if(this->authors == p.authors){
        return this->year < p.year;
    }
    return this->authors < p.authors;
}

bool Publication::operator>(const Publication& p){

    if(this->authors == p.authors){
        return this->year > p.year;
    }
    return this->authors > p.authors;
}
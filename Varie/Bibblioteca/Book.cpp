#include "Book.h"




Book::Book(int b_id, std::string tt, std::vector<std::string> au, int yy,
                std::string posiz,double val): book_id{b_id},title{tt},year{yy}, 
                    position{posiz}, value{val}, authors{au} { }




bool Book::operator<(const Book&  other) const{

    if(authors==other.authors)  
        return this->year<other.year;
    else
        return this->authors< other.authors;


}

int Book::getID() const{
    return book_id;
}

void Book::print() const
{

    std::cout<< std::left<<std::setw(4)<< book_id <<": "<<std::setw(25)<<title
        <<" ( "<<year << " )" << std::setw(4) <<position << " " << value <<" $\n";
    
    for (auto i : authors)
        std::cout<<i<<"  ";
    
    

    std::cout<< "\n";
    return;
}

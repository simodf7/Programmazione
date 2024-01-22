#include "Borrow.h"

Borrow::Borrow(const Book& book, Date dateofB): 
    Book{book}, dateOfBorrow{dateofB}, dateOfRestituion{dateofB}{

    for(int i=0;i<30;i++)  ++dateOfRestituion;
}

Borrow::Borrow(const Book& book,  Date dateB ,Date dateR):Book{book}, dateOfBorrow{dateB}
{
    if(dateR<dateB) 
        throw std::invalid_argument{" DateofRestituion is lower thn dateof Borrow"};
    
    dateOfRestituion=dateR;

}

void Borrow::print() const  
{
    Book::print();

    std::cout<< " \ndate of borrow:" <<dateOfBorrow;
    std::cout<< " , date of Restituion:" <<dateOfRestituion;
    std::cout<<"\n \n";
}

const Date& Borrow::getDateofBorrow() const
{

    return dateOfBorrow;
    
}

const Date& Borrow::getDateofRestituion() const
{
    return dateOfRestituion;
}

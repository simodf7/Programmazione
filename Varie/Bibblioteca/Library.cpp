#include "Library.h"


Library::Library(std::vector<Book> v):books{v}{
    
}

void Library::BorrowBook(int ID , Date datOfB){


    for (auto it=books.begin();it!=books.end(); ++it)
    {
        if(ID==it->getID()){
            
            Borrow b{*it , datOfB};
            inserOrder(b);
            books.erase(it);
            return;
        }
    }

    throw std::invalid_argument{" Book not found"};
    
    
}

double Library::valueExpired( const Date& dd) {

    double sum{0};

    for (auto p = listofBorrow.begin(); p!=listofBorrow.end(); p++)
    {
        if(p->getDateofRestituion() <dd){
            sum+=p->getValue();

        }
    }
    return sum;

}

void Library::print() const
{   
    std::cout<< "\nLibri nella Bibblioteca:\n";

    for (auto i : books)
        i.print();

    std::cout<< "\nLibri in prestito:\n";
    for (auto p = listofBorrow.begin(); p !=listofBorrow.end(); ++p)
    {
        (*p).print();
    }
    
    
    
    
}

double Library::returnBook(int Id)
{
    double res{0};
    Date today{16,5,2022};
    

    for (auto  p =listofBorrow.begin() ;p!=listofBorrow.end(); p++)
    {
        if(Id==p->getID()){
            {
                Date dd{p->getDateofRestituion()};
               while (dd<today){
                   res++;
                   dd++;
                
               }
                books.push_back(*p);
                listofBorrow.erase(p);
                return res;

            }
        }
    }
    
    
}

void Library::inserOrder(const Borrow& b)
{
    for (auto p = listofBorrow.begin(); p!=listofBorrow.end(); ++p)
    {
        if(p->getDateofBorrow()<b.getDateofBorrow())
            listofBorrow.insert(p,b);

    }

    listofBorrow.push_back(b);
    
}



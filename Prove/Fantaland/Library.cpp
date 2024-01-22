#include "Library.h"


void Library::insertBook(Book& b){

    for(auto j = bib.begin(); j != bib.end(); j++){
        if( b < (*j)){
            bib.insert(j,b);
            return;
        }
    }
    
    bib.push_back(b);
    
}

void Library::borrow(const Book& b, const Date& d){

    Borrow b1(b,d);

    for(auto j=loan.begin(); j != loan.end(); j++){
        if(d+30 < (*j).getResDate()){
            loan.insert(j,b1);
            return;
        }
    }

    loan.push_back(b1);

    
}

void Library::valueExpired(Date& d){

    float sum = 0.0;
    for(auto j = loan.begin(); j != loan.end(); ++j){
        if((*j).getResDate() < d){    
            std::cout << "Current value: " << j->getValue() << "\n"; 
            sum += j->getValue();
            std::cout << "Current sum: " << sum << "\n"; 
        }
    }


    std::cout << "Total sum: " << sum << "\n";
    

    
}

void Library::printBooks(){

    for(auto j = bib.begin(); j != bib.end(); j++){
        (*j).print();
    }
    

}


void Library::printBorrows(){
    
    for(auto j = loan.begin(); j != loan.end(); j++){
        (*j).print();
    }

}

void Library::returnBook(const Book& b, Date& d){

    int sum{0};
    Date d1;

    for(auto j = loan.begin(); j!= loan.end(); j++){

        if(j->getId() == b.getId()){
            d1 = (*j).getResDate();
            //std::cout << d1 << "\n";
            while(d1 != d){
                //std::cout << d1 << "\n";
                d1++;
                //std::cout << d1 << "\n";
                sum++;
            } 
            loan.erase(j);
            break;
        }

    }


    std::cout << "Fee: " << sum << "\n"; 



}
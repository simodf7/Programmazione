#include <iostream>
#include "Library.h"



int main(){

    Date d1(1,1,2021);
    Date d2(5,1,2022);
    Date d3(6,23, 2022);
    Date odierna(7,10,2022);

    Book b1(45, {"Michele Ceccarelli", "Alfonso Michelini"}, "L'arte della zappa", 2020,"jaoj", 45.20);
    Book b2(46, {"Anim Milos", "Franco Ocon", "Jan Palaz"}, "Osso", 2010 ,"joj", 115);
    Book b3(47, {"Michele Ceccarelli", "Carlo Magno"}, "Pelata", 2007,"lmo", 2.50);

    Library mon;
    mon.insertBook(b1);
    mon.insertBook(b2);
    mon.insertBook(b3);

    mon.printBooks();

    mon.borrow(b1,d1);
    mon.borrow(b2,d2);
    mon.borrow(b3,d3);

    mon.printBorrows();

    
    mon.valueExpired(odierna);
    mon.returnBook(b1, odierna);

    mon.printBorrows();



};
#include <iostream>
#include "Library.h"
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    Date today{16,5,2022};
    std::vector<Book> books;    


    Book b1(1,"the art",{"Donald"},1968,"A/1",13.4);
    Book b2(2,"algo",{"Nik"},1976,"A/2",15.4);
    Book b4(3," the design ",{"Alfo"},1974,"B/1",22.3);
    Book b5(5,"the C",{"Brian"},1978,"B/2",11.5);

    
    books.push_back(b1);
    books.push_back(b2);
    books.push_back(b4);
    books.push_back(b5);


    std::sort(books.begin(),books.end());


    Library mylib(books);

    mylib.BorrowBook(1,Date(15,4,2022));
    mylib.BorrowBook(5,Date(9,1,2022));
    mylib.BorrowBook(3,Date(2,1,2022));



    mylib.print();
    mylib.valueExpired(today);

    std::cout<<"\n The value "<<mylib.valueExpired(today)<< " ";
    std::cout<< mylib.returnBook(3);

    

    return 0;
}

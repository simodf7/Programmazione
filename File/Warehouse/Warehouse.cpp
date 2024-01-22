#include "Warehouse.h"


Warehouse::Warehouse(int cd,std::string nm,int qty,double pr):code{cd},quantity{qty},
price{pr}
{
    setName(nm);
}




void Warehouse::setName(std::string nm){

    size_t length{nm.length()};   // .length() restituisce un size_t
    length = (length < NAME_MAX_LENGHT) ? length : NAME_MAX_LENGHT;
    nm.copy(name, length);
    name[length] = '\0';   // append null char

}
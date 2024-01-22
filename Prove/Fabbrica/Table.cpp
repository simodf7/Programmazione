#include "Table.h"
#include "iostream"

Table::Table(int c, const std::string& w , const  std::string& wg, float p): col{c}, woodType{w}, woodSeller{wg}, price{p} {}


void Table::print() const{

    std::cout << "Color: " << col << "\nWood: " << woodType << "\nSeller: " << woodSeller 
    << "\nPrice (x cm^2): " << price << "\n"; 
}


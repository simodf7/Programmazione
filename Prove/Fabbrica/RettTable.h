#ifndef RETTABLE_H
#define RETTABLE_H

#include "Table.h"

#include <iostream>

class RettTable: public Table{

    private: 
        float base;
        float height;


    public:
        RettTable(int c, const std::string& w , const  std::string& wg, float p, float b, float h): Table(c,w,wg,p), base{b}, height{h} {}
        float getArea() const {return base*height;}
        virtual void print() const{
            Table::print();
            std::cout << "Base: " << base << "\nHeight: " << height << "\n"; 
        }

};




#endif


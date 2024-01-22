#ifndef TTABLE_H
#define TTABLE_H

#include "Table.h"
#include <iostream>


class TTable: public Table{

    private: 
        float base;
        float height;


    public:
        TTable(int c, const std::string& w , const  std::string& wg, float p, float b, float h): Table(c,w,wg,p), base{b}, height{h} {}
        float getArea() const {return (base*height)/2;};
        virtual void print() const{
            Table::print();
            std::cout << "Base: " << base << "\nHeight: " << height << "\n"; 
        }

};


#endif


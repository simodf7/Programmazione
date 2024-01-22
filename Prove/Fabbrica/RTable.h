#ifndef RTABLE_H
#define RTABLE_H

#include "Table.h"
#include <iostream>


class RTable: public Table{

    private: 
        float radius;


    public:
        RTable(int c, const std::string& w , const  std::string& wg, float p, float r): Table(c,w,wg,p), radius{r} {}
        float getArea() const {return (3.14*radius*radius);}
        virtual void print() const{
            Table::print();
            std::cout << "Radius: " << radius << "\n"; 
        }

};



#endif


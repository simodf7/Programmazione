#ifndef TABLE_H
#define TABLE_H

#include "string"

class Table{

    private:
        int col;
        std::string woodType;
        std::string woodSeller;
        float price;

    public:
        Table(int = 0, const std::string& = "", const std::string& = "", float =0.0);
        virtual float getArea() const=0;
        virtual void print() const;
        float getPrice() const {return price;}



};



#endif
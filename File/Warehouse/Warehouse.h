#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <iostream>
#include <string>
#include <iomanip>

#define NAME_MAX_LENGHT 15


class Warehouse
{
public:
    Warehouse(int cd=0,std::string nm=" ",int qty=0,double pr=0);
    

    void setCode(int cd) { code=cd;}
    int  getcode()const{ return code;}

    void setName(std::string nm);
    std::string getName()const{return name;}

    void setQuantity(int qty) { quantity=qty;}
    int getQuantity()const {return quantity;}


    void setPrince(double pr) { price=pr;}
    double getPrice()const{ return price;}


private:
    int code;
    char name[NAME_MAX_LENGHT];
    int quantity;
    double price;

};

#endif
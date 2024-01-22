#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <list>
#include "Booking.h"
#include "Date.h"


class Hotel{

    private:
        std::string name;
        int category;
        float price;
        std::list<Booking> bookList;

    public:
        Hotel(const std::string& n, int c, float p):
        name{n}, category{c}, price{p}, bookList{} {}

        void insertReservation(const Booking& b){
            for(auto j = bookList.begin(); j != bookList.end(); j++){
                if(b.getBookDate() < (*j).getBookDate()){
                    bookList.insert(j, b);
                    return;
                }
            }
            bookList.push_back(b);
        }

        std::string getName() const {return name;}
        std::list<Booking> getList() const {return bookList;}
        int getCat() const {return category;} 

        bool checkDate(const Date& d){

            bool check{false};
            for(auto j = bookList.begin(); j != bookList.end(); j++){
                if((*j).getBookDate() == d){
                    check = true;
                    return check;
                }
            }


            return check;
        }
        

        void print(){
            std::cout << getName() << ", " << getCat() << " Stars, Bookings: \n";
            for(auto j = bookList.begin(); j != bookList.end() ; j++){
                (*j).printBooking();
            }
            std::cout << "\n";
        } 


};

#endif
#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Date.h"

class Booking{

    private:
        std::string clientName;
        int creditCard;
        Date bookingDate;
    public:
        Booking(const std::string& n, int c, const Date& d):
        clientName{n}, creditCard{c}, bookingDate{d} {}
        std::string getCLient() const {return clientName;}
        Date getBookDate() const {return bookingDate;}
        void printBooking(){
            std::cout << clientName << ", " << bookingDate << "\n";
        }

};


#endif
#ifndef COMPANY_H
#define COMPANY_H

#include "Hotel.h"
#include "Booking.h"
#include <vector>
#include <algorithm>

class Company{

    private:
        std::vector<Hotel> hotels;

    public:
        Company(): hotels{} {};
        void insertHotel(const Hotel&);
        void insertBooking(const std::string& n, int c, const Date& d, int cat);
        void printHotels();
        //bool compare(Hotel , Hotel );

};


#endif
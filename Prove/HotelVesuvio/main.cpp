#include "Company.h"
#include <iostream>


int main(){

    Company dif;
    Date d1{2,1,2022};
    Date d2{5,6,2022};
    Date d3{3,4,2022};
    Date d4{2,8,2022};

    Hotel h1("Hotel Vesuvio", 5, 150.35);
    Hotel h2("Hotel Serapide", 4, 78.25);
    Hotel h3("Zamorisia", 3, 45.60);
    Hotel h4("San Pellegrino", 3, 10.50);
    Hotel h5("San Giiba", 3, 10.50);
    Hotel h6("San Francesco", 3, 10.50);
    Hotel h7("San Polonio", 3, 10.50);

    Booking b1("Di Fraia", 41165161, d1);
    Booking b2("Cocca", 494565646, d1);
    Booking b3("Zolapinto", 31846846 , d2);
    Booking b4("Danna", 453356 , d3);
    Booking b5("Donna", 456 , d1);

    h1.insertReservation(b2);
    h2.insertReservation(b1);
    h2.insertReservation(b4);
    h3.insertReservation(b3);
    h5.insertReservation(b5);

    dif.insertHotel(h1);
    dif.insertHotel(h2);
    dif.insertHotel(h5);
    dif.insertHotel(h4);
    dif.insertHotel(h3);
    dif.insertHotel(h6);
    dif.insertHotel(h7);


    dif.printHotels();

    std::cout << "---------------------\n";

    // h1.printHotel();
    // h2.printHotel();
    // h3.printHotel();
    // h4.printHotel();

    //std::cout << "---------------------\n";

    //dif.insertBooking("DiMatteo", 595959, d3, 3);
    // h2.printHotel();
    //dif.insertBooking("alfonso", 664655, d1, 3);
    // h3.printHotel();
    dif.insertBooking("giuan", 54464, d1, 3);

    //std::cout << "---------------------\n";

    dif.printHotels();
};
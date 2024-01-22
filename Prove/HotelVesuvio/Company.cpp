#include "Company.h"
#include "algorithm"


void Company::insertHotel(const Hotel& h){

    for(auto j = hotels.begin(); j != hotels.end(); j++){
        if(h.getList().size() > (*j).getList().size()){
            hotels.insert(j, h);
            return;
        }
    }

    hotels.push_back(h);
}

void Company::insertBooking(const std::string& n, int c, const Date& d, int cat){

    Booking b(n,c,d);
    


    std::vector<Hotel>::iterator it;
    //std::vector<Hotel>::iterator j;
    for(it = hotels.begin(); it != hotels.end(); it++){
        if(it->getCat() == cat && !(it->checkDate(d))){
            it->insertReservation(b);
            break;
        }
    }

    // int i{1};
    // while(((it-i) != hotels.begin()-1) && (it->getList().size() > (it-i)->getList().size())){
    //     // std::cout << "/Debug end: " << hotels.begin()-1 << "\n";
    //     // std::cout << "/Debug it: " << it-i << "\n";
    //     std::cout << "/Debug iteration: " << i << "\n";
    //     std::cout << "/Debug size current: " << it->getList().size() << "\n";
    //     std::cout << "/Debug size previous: " << (it-1)->getList().size() << "\n";
    //     j = it-1;
    //     Hotel temp = *it;
    //     *it = *(it-i);
    //     *(it-i) = temp;
    //     it = j;
    //     i++;
    // }
        
    // for(auto j=hotels.begin();j!=hotels.end();j++){

    //     if(j->getList().size() < it->getList().size()){

    //         Hotel temp = *it;
    //         *it = *j;
    //         *j = temp;
    //         break;
    //     }
    // }


   std::sort(hotels.begin(), hotels.end(), [] (const Hotel& lhs, const Hotel& rhs) {return lhs.getList().size() > rhs.getList().size(); });

}
    

void Company::printHotels(){

    for(auto j = hotels.begin(); j != hotels.end(); j++){
        (*j).print();
    }
}





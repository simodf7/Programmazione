#include "City.h"
#include <iostream>


void City::addMeasurement(int i, Date& d, float p){
    
    for(auto j = rilevatori.begin(); j != rilevatori.end(); j++){
        if((*j).getID() == i){
            for(auto k = j->getRelList()->begin(); k != j->getRelList()->end(); k++){
                if(d < k->getRelDate()){
                    j->getRelList()->insert(k, Rilevamento(d,p));  
                    break;            
                }
            }
            j->getRelList()->push_back(Rilevamento(d,p));
            break;
        }
    }

}

float City::meanCO2Zone(Date& d1, Date& d2, int x1, int y1, int x2, int y2){


    float sum{0.0}; 
    int n{0};


    for(auto j = rilevatori.begin(); j!= rilevatori.end(); j++){
        if(j->getX() <= x2 && j->getX() >= x1 && j->getY() >= y1 && j->getY()<=y2){
            for(auto k = j->getRelList()->begin(); k != j->getRelList()->end(); k++){
                if(d1 <= k->getRelDate()  &&  k->getRelDate() <= d2){
                    //std::cout << "/Debug: " << k->getPPM()  << "\n";
                    //std::cout << "/Debug: " << n  << "\n";
                    sum += k->getPPM();
                    n++;
                }
            }
        }
    }

    if(n == 0){
        return 0;
    }

    return sum/n;
    
}

void City::insertRilev(const Rilevatore& r){
    
    // Rilevatore r(nStation, x,y);
    rilevatori.push_back(r);
    //nStation++;
   // std::cout << "2";
    
}

void City::printRilev(){
    
    for(auto j = rilevatori.begin(); j!= rilevatori.end(); j++){
        std::cout << "-- " << j->getID() << ": (" << j->getX() << "," << j->getY() << ")\n"; 
    }
}



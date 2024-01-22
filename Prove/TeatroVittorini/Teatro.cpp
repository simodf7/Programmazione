#include "Teatro.h"
#include <iostream>


Teatro::Teatro(int n): numPosti{n} {

    for(int i=0; i<n; i++){
        teatro.push_back(Posto(i,false,false));
    }

};




void Teatro::prenota(int id){

    for(auto j=teatro.begin(); j!= teatro.end(); j++){
        if (id == j->getId() && !(j->getBooked())){
            j->setBooked(true);
            return;
        }
    }
}

void Teatro::acquista(int id){
    for(auto j=teatro.begin(); j!= teatro.end(); j++){
        if (id == j->getId() && j->getBooked() && !(j->getBought())){
            j->setBought(true);
            return;
        }
    }
}

void Teatro::liberaprenotato(int id){

    for(auto j=teatro.begin(); j!= teatro.end(); j++){
        if (id == j->getId() && j->getBooked()){
            j->setBooked(false);
            return;
        }   
    }
    
}

void Teatro::visualizza_disponibili(){
    std::cout << "Disponibili: \n";
    for(auto j=teatro.begin(); j!= teatro.end(); j++){
        if (!(j->getBooked())){
            std::cout << j->getId() << ", " ; 
        }
    }
}

void Teatro::visualizza_prenotati(){
    std::cout << "Prenotati: \n";
    for(auto j=teatro.begin(); j!= teatro.end(); j++){
        if (j->getBooked()){
            std::cout << j->getId() << ", " ; 
        }
    }
    
}
    




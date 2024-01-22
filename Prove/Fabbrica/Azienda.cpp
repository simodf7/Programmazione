#include "Azienda.h"



void printVector(){

    for(auto j= vet.begin(); j!= vet.end(); j++){
        std::cout << (*j)->toString();
    }
}
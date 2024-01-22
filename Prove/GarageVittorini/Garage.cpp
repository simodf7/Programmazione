#include "Garage.h"
#include <typeinfo>
#include <iostream>
#include <fstream>


int Garage::insertVehicle(Motore* m){

    // Auto* t;
    // t = dynamic_cast<Auto*>(m);

    // std::string s = typeid(*m).name();
    // std::cout << s << "\n";

    // if (s != "4Auto" && s != "4Moto"){
    //     throw std::invalid_argument("NO AUTO, NO MOTO");
    // }   

    for(int i=0; i<20; i++){
        if(garage[i] == nullptr){
            garage[i] = m;
            (*m).setPosto(i);
            //std::cout << "/Debug Posto: " << garage[i]->getPosto() << "\n";  
            return i;
        }
    }

   return -1;


}

void Garage::eraseVehicle(int i){garage[i] = nullptr;}

void Garage::printGarage(){

    std::cout << "Posti Occupati: ";
    for(auto j = garage.begin(); j!= garage.end(); j++){
        if (*j != nullptr){
            std::cout << (*j)->getPosto() << "\n";
        }
    }
    
    // for(int i=0; i<20; i++){
    //    std::cout << garage[i]->getPosto() << "\n"; 
    // }

}

void Garage::printInFile(const std::string& fileName){

    std::fstream file(fileName, std::ios::out);

    if(!file){
        std::cerr << "File could not be opened\n";
        exit(EXIT_FAILURE);
    }


    file << "Posti Occupati ";
    for(auto j = garage.begin(); j!= garage.end(); j++){
        if (*j != nullptr){
            file << (*j)->getPosto() << "\n";
        }
    }

    file.close();
}

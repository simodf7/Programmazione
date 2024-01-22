#include "VettoreRilev.h"
#include <fstream>
#include <iostream>


VettoreRilev::VettoreRilev(const std::string& p):periodo{p}, rilevamenti{} {
    if (periodo == "settimanale"){
       for(int i=0; i<7; i++){
        rilevamenti.push_back(Rilevamento{"Campania", "Napoli", "Pozzuoli"});
       }
    }
    else if (periodo  == "bisettimanale"){
        for(int i=0; i<14; i++){
        rilevamenti.push_back(Rilevamento{"Campania", "Napoli", "Pozzuoli"});
       }
    }
    else{
        for(int i=0; i<31; i++){
        rilevamenti.push_back(Rilevamento{"Campania", "Napoli", "Pozzuoli"});
       }
    }
}

void VettoreRilev::carica_TMax(const std::string& f){
    
    std::ifstream file(f, std::ios::in);

    if(!file){ 
        std::cerr << "File cpuld not be opened\n";
        exit(EXIT_FAILURE);    
    }

    int t;
    for(int i=0; i<rilevamenti.size(); i++){
        file >> t;
        rilevamenti[i].setTMax(t);
    }

    file.close();

}


void VettoreRilev::carica_Tmin(const std::string& g){
    
    std::ifstream file(g, std::ios::in);

    if(!file){ 
        std::cerr << "File cpuld not be opened\n";
        exit(EXIT_FAILURE);    
    }

    int t;
    for(int i=0; i<rilevamenti.size(); i++){
        file >> t;
        rilevamenti[i].setTMin(t);
    }

    file.close();

}

void VettoreRilev::MedieT(){

    float min{0.0};
    float max{0.0};
    for(int i=0; i< rilevamenti.size(); i++){
        max += rilevamenti[i].getTMax();
       // std::cout << "debug: " << max << "\n";
        min += rilevamenti[i].getTMin();
    }


    std::cout << "Media Massima: " << max/rilevamenti.size() << "\n";
    std::cout << "Media Minima: " << min/rilevamenti.size() << "\n";
}




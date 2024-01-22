#include "Ups.h"



void Ups::insertPackage(Package& p){

    for(auto j = packages.begin(); j != packages.end(); j++){
        if(p.getDate() < (*j)->getDate()){
            packages.insert(j,&p);
            return;
        }
    }

    packages.push_back(&p);
    
}

float Ups::weekly_earnings(){

    float sum{0.0};
    for(auto j = packages.begin(); j != packages.end(); j++){
        sum += (*j)->getEarning();
    }

    return sum;
}

void Ups::findType(Package* s){

    Foreign* p = dynamic_cast<Foreign*>(s);

    if(p != nullptr){
        std::cout << "\nPacco straniero\n";
    }
    else std::cout << "Pacco europeo\n";
    
}



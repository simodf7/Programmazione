#include "Fabric.h"
#include <iostream>

Fabric::Fabric(): wareHouse{} {}

void Fabric::insertTable(Table& t){

    Table* pp = &t;

    for(auto p = wareHouse.begin(); p != wareHouse.end(); p++){
        
        if(pp->getArea() < (*p)->getArea()){
            wareHouse.insert(p, pp);
            return;
        }
    }

    wareHouse.push_back(pp);
}

float Fabric::summarizeWharehouse(){
    float sum{0.0}; 
    for(auto p = wareHouse.begin(); p != wareHouse.end(); p++){
        sum += ((*p)->getArea())*((*p)->getPrice());
    }

    return sum;
}

void Fabric::printList(){

    for(auto p = wareHouse.begin(); p != wareHouse.end(); p++){
        (*p)->print();
        std::cout << "\n";
    }

    
}






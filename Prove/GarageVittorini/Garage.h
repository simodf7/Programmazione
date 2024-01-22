#ifndef GARAGE_H
#define GARAGE_H

#include "Motore.h"
#include "Automobile.h"
#include "Motocicletta.h"
#include <array>

class Garage{

    private:
        std::array<Motore*,20> garage;
        int posto;

    public:
        Garage(): garage{} {}
        int insertVehicle( Motore*);
        void eraseVehicle(int);
        void printGarage();
        void printInFile(const std::string&);


};




#endif
#include "Garage.h"
#include <iostream>

int main(int argc, char** argv){

    Garage mediterraneo;

    Motore m1("Jaguar", "Di Fraia");
    Motore m2("Ferrari", "Di Fraia");
    Motore m3 ("Aston", "Di Fraia");
    Motore m4 ("Punto", "Di Fraia");

    std::cout << mediterraneo.insertVehicle(new Auto(m1,"Benzina"));
    std::cout << mediterraneo.insertVehicle(new Auto(m2,"Benzina"));
    std::cout << mediterraneo.insertVehicle(new Auto(m3,"Gas"));
    std::cout << mediterraneo.insertVehicle(&m1);

    mediterraneo.printGarage();

    mediterraneo.eraseVehicle(1);

    mediterraneo.printGarage();
    mediterraneo.printInFile(argv[1]);
    



}
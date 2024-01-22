#include <iostream>
#include <string>
#include "Vehicle.h"


MotorVehicle::MotorVehicle(std::string m, std::string f, int y, std::string c, int e)
    : make{m},fuelType{f},yearOfManufacture{y},color{c},engineCapacity{e}{
    }

void MotorVehicle:: setMake(std:: string m) {
    make = m;
}

std::string MotorVehicle:: getMake() const {
    return  make;
}

void MotorVehicle:: setFuelType(std:: string f) {
    fuelType = f;
}

std::string MotorVehicle:: getFuelType() const {
    return fuelType;
;
}

void MotorVehicle:: setYear(int y) {
        yearOfManufacture = y;
    }

int MotorVehicle:: getYear() const{
    return yearOfManufacture;
}

void MotorVehicle:: setColor(std::string c){
    color = c;
}

std::string MotorVehicle:: getColor() const {
    return color;
}

void MotorVehicle:: setCapacity(int e){
    engineCapacity = e;
}

int MotorVehicle:: getCapacity() const{
    return engineCapacity;
}

void MotorVehicle:: displayCarDetails(){
    std::cout << "Make: " << getMake() << std::endl;
    std::cout << "Fuel Type: " << getFuelType() << std::endl;
    std::cout << "Year Of Manufacture: " << getYear() << std::endl;
    std::cout << "Color: " << getColor() << std::endl;
    std::cout << "Engine Capacity: " << getCapacity() << std::endl;
};

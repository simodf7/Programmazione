#include <iostream>
#include <string>

class MotorVehicle {
public: 

    MotorVehicle (std::string m, std::string f, int y, std::string c, int e);

    void setMake(std:: string m);
    std::string getMake() const;

    void setFuelType(std:: string f);
    std::string getFuelType() const;

    void setYear(int y);
    int getYear() const;
    
    void setColor(std::string c);
    std::string getColor() const;

    void setCapacity(int e);
    int getCapacity() const;

    void displayCarDetails();

private:
    std::string make;
    std::string fuelType;
    int yearOfManufacture;
    std::string color;
    int engineCapacity;
};
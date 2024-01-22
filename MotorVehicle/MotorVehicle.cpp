#include <iostream>
#include "Vehicle.h"
using std::cout;
using std::endl;


int main(){
    MotorVehicle motor1("Suzuki", "B32", 2013, "Red", 345);
    MotorVehicle motor2("BMW", "F43", 2017, "Grey", 302);
    cout << endl;
    motor1.displayCarDetails();
    cout << endl;
    motor2.displayCarDetails();
    cout << endl;
}
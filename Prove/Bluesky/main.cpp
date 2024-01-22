#include "City.h"

int main(){

    City bluesky;
    // bluesky.insertRilev(0,1);
    // bluesky.insertRilev(1,1);
    // bluesky.insertRilev(2,1);
    // bluesky.insertRilev(3,1);
    // bluesky.insertRilev(2,0);
    // bluesky.insertRilev(0,2);
    // bluesky.insertRilev(0,3);
    Rilevatore r1(1, 0, 1);
    Rilevatore r2(2, 1, 1);
    Rilevatore r3(3, 2, 1);
    Rilevatore r4(4, 3, 1);
    Rilevatore r5(5, 2, 0);
    Rilevatore r6(6, 0, 2);
    Rilevatore r7(7, 0, 3);

    //std::cout << "a\n";
    bluesky.insertRilev(r1);
    //std::cout << "b\n";
    bluesky.insertRilev(r2);
    ///std::cout << "b\n";
    bluesky.insertRilev(r3);
    //std::cout << "b\n";
    bluesky.insertRilev(r4);
    //std::cout << "b\n";
    bluesky.insertRilev(r5);
    //std::cout << "b\n";
    bluesky.insertRilev(r6);
    //std::cout << "b\n";
    bluesky.insertRilev(r7);
    //std::cout << "b\n";


    //std::cout << "c\n";
    bluesky.printRilev();
    //std::cout << "d\n"; 
    //std::cout << "\n";

    Date d1(12,15,2022);
    Date d2(10,5,2022);
    Date d3{2,8,2022};
    Date d4{6,1,2022};
    Date d5{4,15,2022};
    Date d6{7,10,2022};
    Date d7{3,19,2022};

    
    bluesky.addMeasurement(3,d1,12.6);
    bluesky.addMeasurement(3,d2,4.8);
    bluesky.addMeasurement(1,d3,5.9);
    bluesky.addMeasurement(2,d4,10.1);
    bluesky.addMeasurement(4,d5,6.6);
    bluesky.addMeasurement(5,d6,0.2);
    bluesky.addMeasurement(6,d7,1.2);


    Date d8{3,1,2022};
    Date d9{9,1,2022};
    std::cout<<"PPM: " << bluesky.meanCO2Zone(d8,d9,0,0,20,20);
    



}
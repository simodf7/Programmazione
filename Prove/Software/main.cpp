#include "Project.h"
#include <iostream>

int main(){

    Date d1(8,17,2021);
    Date d2(8,17,2022);
    Date d3(4,6,2022);
    Project p1("Iphone", "Musk", 56000, d1,d2);
    Programmer pro1("Cocca", 40);
    Programmer pro2("Colapinto", 75);
    Programmer pro3("Danna", 2);
    Programmer pro4("Dimatteo", 100);
    Task t1("Taglio", d3, 50, pro1);
    Task t2("Pulitura", d3, 32, pro2);
    Task t3("Schermo", d3, 100, pro4);

    //std::cout << "m\n";
    p1.insertProg(pro1);
    //std::cout << "a\n";
    p1.insertProg(pro2);
    //std::cout << "a\n";
    p1.insertProg(pro3);
    p1.insertProg(pro4);
    //std::cout << "a\n";

    p1.insertTasks(t1);
    p1.insertTasks(t2);
    p1.insertTasks(t3);

   // std::cout << "b\n";
    p1.printProg();
    //std::cout << "c\n";
    p1.printTask();
    p1.workloadDeveloper();


}
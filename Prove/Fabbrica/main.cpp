#include "Fabric.h"
#include <list>
#include <iostream>



int main(int argc, char const *argv[])
{
    Fabric fab;
    RTable roundt(45, "quercy", "ups", 8.90, 4.5);
    RettTable rett(45, "quercy", "ups", 8.90, 3, 4);
    TTable tt(45, "quercy", "ups", 8.90, 5,6);

    fab.insertTable(roundt);
    fab.insertTable(rett);
    fab.insertTable(tt);

    std::cout << "The sum is: " << fab.summarizeWharehouse() << "\n";
    std::cout << "\n"; 
    fab.printList();
    return 0;
}

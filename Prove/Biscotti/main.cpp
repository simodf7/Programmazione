#include "Eba.h"


int main(){

    //std::cout << "0";
    Eba draghi;
    //std::cout << "1";

    //std::cout << "a";
    draghi.builtGraph();
    //std::cout << "b";
    draghi.printGraph();
    //std::cout << "c";

    std::cout << "\n";
    draghi.cluster(1);

}
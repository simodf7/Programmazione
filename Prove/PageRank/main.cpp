#include "Web.h"
#include <iostream>

int main(){
    
    Web www(6);
    std::cout << '\n';
    www.printRanks();
    std::cout << "Updating ranks ... \n";
    // /std::cout << "a";
    // www.insertPage();
    //std::cout << "b";
    www.addLink(0,3);
    //std::cout << "e";
    www.addLink(0,5);
    //std::cout << "f";
    www.addLink(1,2);
    //std::cout << "g";
    www.addLink(2,0);
    //std::cout << "h";
    www.addLink(2,1);
    //std::cout << "i";
    www.addLink(2,2);
    //std::cout << "j";
    www.addLink(2,3);
    //std::cout << "k";
    www.addLink(3,0);
    //std::cout << "l";
    www.addLink(3,2);
    //std::cout << "m";
    www.addLink(4,2);
    //std::cout << "n";
    www.addLink(5,3);
    //std::cout << "o";
    www.addLink(5,1);
    //std::cout << "p";
    www.pageRank();
    www.printRanks();
    www.iteratePageRank();
    std::cout << "Updating ranks ... \n";
    www.printRanks();
    std::cout << '\n';


}
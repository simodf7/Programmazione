#include "Web.h"
#include <iostream>

int main(){

    Web www(6);

    //std::cout << "a";
    www.insertPage();
    //std::cout << "b";
    www.addlinks(0,3);
    //std::cout << "e";
    www.addlinks(0,5);
    //std::cout << "f";
    www.addlinks(1,2);
    //std::cout << "g";
    www.addlinks(2,0);
    //std::cout << "h";
    www.addlinks(2,1);
    //std::cout << "i";
    www.addlinks(2,2);
    //std::cout << "j";
    www.addlinks(2,3);
    //std::cout << "k";
    www.addlinks(3,0);
    //std::cout << "l";
    www.addlinks(3,2);
    //std::cout << "m";
    www.addlinks(4,2);
    //std::cout << "n";
    www.addlinks(5,3);
    //std::cout << "o";
    www.addlinks(5,1);
    //std::cout << "p";


    www.printRanks();
    std::cout << "\n";
    www.rankUpdate();
    www.printRanks();

    std::cout << "\n";
    www.iterateRanks();
    www.printRanks();

}
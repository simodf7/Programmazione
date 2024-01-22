#include "Teatro.h"
#include <iostream>

int main(){
   // std::cout << "0";
    Teatro Sancarlo(10);
    //std::cout << "1";

   // std::cout << "a";
    Sancarlo.visualizza_disponibili();
   // std::cout << "b";
    Sancarlo.prenota(4);
    Sancarlo.prenota(5);
    Sancarlo.prenota(6);
    Sancarlo.prenota(7);
    Sancarlo.prenota(8);
    Sancarlo.prenota(9);

    Sancarlo.liberaprenotato(5);
    Sancarlo.visualizza_prenotati();
    Sancarlo.acquista(9);
    Sancarlo.acquista(8);
    Sancarlo.acquista(4);
    Sancarlo.visualizza_disponibili();


}
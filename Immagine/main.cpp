#include "Immagine.h" 
#include <iostream>



int main (){
    Immagine m(3,3);
    m.riempMat();
    m.printMat();
    std::cout << "\n";
    
    Immagine m1 = m.insFilter();
    m1.printMat();
    std::cout << "\n";
    
}
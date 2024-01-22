#include <iostream>

int main(){
    int x,y;
    int* c{&x};
    int* f{&y};

    if (c != f){
        std::cout<< "I puntatori puntano a variabili diverse" << std::endl;
        std::cout<< c << std::endl;
        std::cout<< f << std::endl;
    } 

}
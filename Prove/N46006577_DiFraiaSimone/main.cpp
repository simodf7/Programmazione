#include "Comunita.h"
#include <iostream>

int main(){

    Comunita c(4);
    c.insPersona(Persona(0,"Alessio", "Giannini", "Via Rossi", 21));
    c.insPersona(Persona(1,"Renato", "Poggi", "Via Bianchi", 30));
    c.insPersona(Persona(2,"Franco", "Boschi", "Via Gialli", 25));
    c.insPersona(Persona(3,"Raffaele", "Giordano", "Via Verdi", 27));

    c.builtAdiacenza("friend.txt");
    c.printAdiacenza();

    std::cout << "\n";

    c.mediaEtaAmicizia();


}
#ifndef COMUNITA_H
#define COMUNITA_H


#include <vector>
#include "Persona.h"

class Comunita{
    private:
        std::vector<Persona> persone;
        int** adiacenza;
        int nPersone;

    public:
        //siccome nel constructor alloco memoria devo anche opportunamente definire un copy constructor e quindi 
        // seguo la regola dei big three
        Comunita(int);
        ~Comunita();
        Comunita(const Comunita&);
        Comunita& operator=(const Comunita&);

        void insPersona(const Persona&);
        void builtAdiacenza(const std::string&);
        void printAdiacenza();
        void mediaEtaAmicizia();
        




};

#endif
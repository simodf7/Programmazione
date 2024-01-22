#ifndef AUTO_H
#define AUTO_H

#include "Motore.h"

class Auto: public Motore{

    private:
        std::string alimentazione;
    
    public:
        Auto(const Motore& m, const std::string& a): Motore(m), alimentazione{a} {}



};


#endif
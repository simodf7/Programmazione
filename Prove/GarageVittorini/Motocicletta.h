#ifndef MOTO_H
#define MOTO_H

#include "Motore.h"

class Moto: public Motore{

    private:
        std::string tipo;

    public:
        Moto(const Motore& m, const std::string& t): Motore(m), tipo{t} {}


};

#endif
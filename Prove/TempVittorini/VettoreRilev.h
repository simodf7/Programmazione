#ifndef VETTRIL_H
#define VETTRIL_H

#include <vector>
#include "Rilevamento.h"

class VettoreRilev{

    private:
        std::vector<Rilevamento> rilevamenti;
        std::string periodo;

    public:
        VettoreRilev(const std::string& p);
        void carica_TMax(const std::string& f);
        void carica_Tmin(const std::string& g);
        void MedieT();


};


#endif
#ifndef TEATRO_H
#define TEATRO_H

#include "Posto.h"
#include <vector>

class Teatro{
    private:    
        int numPosti;
        std::vector<Posto> teatro;
    public:
        Teatro(int);
        void prenota(int);
        void acquista(int);
        void liberaprenotato(int);
        void visualizza_disponibili();
        void visualizza_prenotati();




};


#endif
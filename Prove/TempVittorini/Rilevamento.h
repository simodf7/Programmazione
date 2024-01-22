#ifndef RILEVAMENTO_H
#define RILEVAMENTO_H

#include "Date.h"
#include <string>
#include <sstream>

class Rilevamento{
    
    // friend std::ostream &operator<<(std::ostream &, const Rilevamento&);
    // friend std::istream &operator>>(std::istream &in, Rilevamento& r){
    //     in >> r;
    //     return in;
    // }

    private:
        std::string regione;
        std::string provincia;
        std::string citta;
        Date dataRil;
        int tMax;
        int tMin;

    public:
        Rilevamento(const std::string& r, const std::string& p, const std::string& c):
        regione{r}, provincia{p}, citta{c}, dataRil{}, tMax{0}, tMin{0} {}

        void setTMax(int i){ 
            if(i<tMin) throw std::invalid_argument("La temperatura massima non puo essere piu piccola della minima\n");
            tMax = i;
        }

        void setTMin(int i){ 
            if(i>tMax) throw std::invalid_argument("La temperatura minima non puo essere piu grande della massima\n");
            tMin = i;
        }

        int getTMax() const {return tMax;}
        int getTMin() const {return tMin;}



};



#endif
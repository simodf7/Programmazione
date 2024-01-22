#ifndef RILEVAMENTO_H
#define RILEVAMENTO_H

#include "Date.h"

class Rilevamento{

    private:
        Date relDate;
        float ppm;   


    public:
        Rilevamento(const Date& d, float p): relDate{d}, ppm{p} {}
        Date getRelDate() const {return relDate;}
        float getPPM() const {return ppm;}



};


#endif
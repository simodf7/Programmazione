#ifndef LAP_H
#define LAP_H

#include <stdexcept>
#include "Driver.h"

class Lap{

    private:
        int numDri;
        int minute;
        int hundreth;
        int thousandth;

    public:
        Lap(int d, int m, int h, int t): numDri{d} {setLapTime(m,h,t);}

        void setLapTime(int m, int h, int t){
            if(t<0 && t>999){throw std::invalid_argument("Thousandths must be between 0 and 999\n");}
            if(h<0 && h>59){throw std::invalid_argument(" Hundreths must be between 0 and 59\n");}

            minute = m;
            hundreth = h;
            thousandth = t;
        }

        int getDriver() const {return numDri;}


};



#endif
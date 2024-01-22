#ifndef CITY_H
#define CITY_H

#include "Rilevatore.h"
#include <vector>

class City{
    private:
        std::vector<Rilevatore> rilevatori;
    public:
        City(): rilevatori{} {}
        void addMeasurement(int, Date&, float);
        float meanCO2Zone(Date&,Date&, int, int, int, int);
        void insertRilev(const Rilevatore&);
        void printRilev();





};


#endif
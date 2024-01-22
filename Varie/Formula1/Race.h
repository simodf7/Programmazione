#ifndef RACE_H
#define RACE_H


#include "Driver.h"
#include <vector>
#include "Lap.h"

class Race{

    private:
        int poleNum;
        Lap fastest;
        //bool grandchelem;
        std::string circuit;
        friend class Championship;
        std::vector<int> positions;

    public:
        Race(const std::string& nam, int n, const Lap& f, std::vector<int> a): circuit{nam}, poleNum{n}, fastest{f}, positions{a} {}
        virtual int getPoleMan() const {return poleNum;}
        // bool checkChelem(){
        //     if ((positions[0] == pole.getNum() && pole.getNum() == fastest.getDriver().getNum())){
        //         grandchelem = true;
        //     }
        // }






};


#endif
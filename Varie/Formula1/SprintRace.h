#ifndef SPRINTRACE_H
#define SPRINTRACE_H

#include "Race.h"


class SprintRace: public Race{

    private:
        std::vector<int> sprint;
        friend class Championship;
    
    public:
        SprintRace(const std::string& nam, const Lap& f, std::vector<int> a, std::vector<int> b): 
        Race(nam, b[0], f, a), sprint{b} {}
        int getPoleMan() const {return sprint[0];}


};



#endif
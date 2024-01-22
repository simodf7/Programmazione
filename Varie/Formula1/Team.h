#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include "Driver.h"

class Team{
    private:
        std::string name;
        std::vector<Driver*> drivers;
        int nPoints;
        int nPoles;
        friend class Championship;

    public:
        Team(const std::string& n):
        name{n}, nPoints{0}, nPoles{0}, drivers{} {}
        bool operator>(const Team& d) {return nPoints > d.nPoints;}


};


#endif
#ifndef CHAMPIONSHIP_H
#define CHAMPIONSHIP_H


#include <list>
#include "Race.h"
#include "Driver.h"
#include "Team.h"
#include "SprintRace.h"

class Championship{

    private:
        std::list<Race*> races;
        std::vector<Driver*> drivers;
        std::list<Team*> teams;
        void updateClass();


    public:
        Championship();
        void insertDriver();
        void insertRace();        
        void insertTeam();
        void driverClassification();
        void constructorClass();
        void printDriverclass();
        void printConstructorClass();
        void addNewRace();


};


#endif
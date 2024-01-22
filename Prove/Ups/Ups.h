#ifndef UPS_H
#define UPS_H

#include <list>
#include "Package.h"
#include "ForeignPackage.h"

class Ups{

    private:
        std::list<Package*> packages;

    public:
        Ups(): packages{} {}
        void insertPackage( Package&);
        float weekly_earnings();
        void findType(Package*);





};


#endif
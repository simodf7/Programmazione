#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include "Date.h"

class Package{

    private:
        std::string mittent;
        std::string destiny;
        Date spedition;
        float kg;
        float earning;
    
    public: 
        Package(const std::string& m, const std::string& d, const Date& s, float k, float e=1):
        mittent{m}, destiny{d}, spedition{s}, kg{k}, earning{e} {}
        Date& getDate() {return spedition;}
        virtual float getEarning() const {return kg*earning;}




};



#endif
#ifndef FOREIGN_H
#define FOREIGN_H

#include "Package.h"

class Foreign: public Package{

    private:    
        std::string country;
        std::string continent;
    
    public:
        Foreign(const Package& p, const std::string& c, const std::string& con):  
        Package(p), country{c}, continent{con} {}
        float getEarning() const{
            if (country  == "USA"){ return Package::getEarning() + 10;}
            if (continent != "Europa"){ return Package::getEarning()+15;}
            return Package::getEarning();
        }

};


#endif
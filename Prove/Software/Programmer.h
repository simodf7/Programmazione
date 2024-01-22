#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <string>


class Programmer{

    private:
        std::string name;
        float costPerHour;


    public:
        Programmer(const std::string& n, float c): name{n}, costPerHour{c} {}
        float getcost() const {return costPerHour;}
        std::string getName() const { return name;}

};

#endif
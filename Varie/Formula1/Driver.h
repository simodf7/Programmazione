#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <sstream>
#include "Date.h"

class Driver{

    private:
        int points;
        int number;
        std::string name;
        std::string surname;
        std::string team;
        //int points;
        int poles;
        int wins;
        int fast;
        friend class Championship;

    public:
        Driver(int num, const std::string& n, const std::string& s, const std::string& t): number{num},
         name{n}, surname{s}, points{0}, poles{0}, wins{0}, fast{0}, team{t} {}
        //const std::string& getSurname() const {return surname;}
        int getNum() const {return number;}
        int getPoint() const {return points;}
        bool operator>(const Driver& d) {return points > d.points;}
        //const Date& getDate() const {return born;}
        // int getAge(const Date& d) const {
        //     int i{0};
        //     Date d1 = born;
        //     while( d1 != d){
        //         d1++;
        //         i++;
        //     }
        //     return i;
        // }

        // const std::string& toString(const Date& d) {
        //     std::ostringstream out;

        //     out << "\nName: " << name << "\nSurname: " << surname
        //       << "\nPoles: " << poles << "\nPoints" << points << "\n";

        //     return out.str();
        // }
};



#endif
#include <iostream>
#include <string>
#include <sstream>
#include "Date.h"
#include <array>

Date::Date(unsigned int d, unsigned int m, unsigned int y)
    : month{m},day{d},year{y}{
    }


void Date:: setMonth(int m) {
    if (m<1 || m>12){
        month=1;
    }
    else month = m;
}

int Date:: getMonth() const {
    return  month;
}

void Date:: setDay(int d) {
    if (d<1 || d>31){
        day=1;
    }
    else day = d;
}

int Date:: getDay() const {
    return day;
}

void Date:: setYear(int y) {
        year = y;
    }

int Date:: getYear() const{
    return year;
}


void Date:: displayDate(){
    std::cout << "The day is: " <<  getDay()  << "/" << getMonth() << "/" << getYear() << std::endl;
};



std::string Date::toString() const {
    std::ostringstream output;
    output << day << '/' << month << '/' << year;
    return output.str();
}


unsigned int Date::checkDay(int testDay) const {
    static const std::array<int, monthsPerYear+1> daysPerMonth{
        0,31,28,31,30,31,30,
        31,31,30,31,30,31};

    if (testDay>0 && testDay <0 <= daysPerMonth[month]){
        return testDay;
    }
    if (month==2 && testDay==29 && (year % 400 ==0 ||(year % 4 ==0 && year %100 !=0))){
        return testDay;
    }
    throw std::invalid_argument("Invalid day for current month and year");
}
#include <iostream>
#include <string>
#include "Date.h"

Date::Date(int m, int d, int y)
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
    std::cout << "The day is: " << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
};

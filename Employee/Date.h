#include <iostream>
#include <string>


#ifndef DATE_H
#define DATE_H

class Date {
public: 
    static const unsigned int monthsPerYear{12};
    explicit Date(unsigned int = 1, unsigned int = 1 , unsigned int = 1900); // Date (int m, int d, int y);
    std::string toString() const;   //date string in month/day/year
   // ~Date(); // destructor

    void setMonth(int m);
    int getMonth() const;

    void setDay(int d);
    int getDay() const;

    void setYear(int y);
    int getYear() const;
    
    void displayDate();

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    unsigned int checkDay(int) const; //utility function to check if day is proper for month and year
};


#endif


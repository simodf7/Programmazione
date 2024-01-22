// Date class definition with overloaded increment operators.
#ifndef DATE_H
#define DATE_H

#include <array>

#include <iostream>
class Date {

    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend Date operator+(int, const Date&);
    friend Date operator+(const Date&, int);
    friend Date operator-(const Date&, int);

public:
    Date(int m = 1, int d = 1, int y = 1900); // default constructor
    void setDate(int, int, int); // set month, day, year
    Date& operator++(); // prefix increment operator
    Date operator++(int); // postfix increment
    Date& operator+=(unsigned int); //add days, modify object
    static bool leapYear(int); // is year a leap year?
    bool endOfMonth(int) const; // is day at the end of month?
    bool operator<(const Date&);
    bool operator>(const Date&);
    bool operator<=(const Date&);
    bool operator>=(const Date&);
    bool operator!=(const Date&);
    bool operator==(const Date&);
    Date& operator=(const Date&);

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const std::array<int, 13> days; // days per month
    void helpIncrement(); // utility function for incrementing date
    void helpDecrement();
};



#endif

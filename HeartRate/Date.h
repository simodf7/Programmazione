#include <iostream>
#include <string>

class Date {
public: 

    Date (int m, int d, int y);

    void setMonth(int m);
    int getMonth() const;

    void setDay(int d);
    int getDay() const;

    void setYear(int y);
    int getYear() const;
    
    void displayDate();

private:
    int month;
    int day;
    int year;
};
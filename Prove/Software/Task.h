#ifndef TASK_H
#define TASK_H

#include <string>
#include "Programmer.h"
#include "Date.h"


class Task{

    private:
        std::string name;
        Date expire;
        int manHour;
        Programmer* resp;

    public:
        Task(const std::string& n, const Date& d1, int h, Programmer& p): name{n}, expire{d1}, manHour{h}, resp{&p} {}
        //~Task(){delete resp;}
        Date getDate()  {return expire;}
        Programmer* getProg() {return resp;}
        int getHours() {return manHour;}

};

#endif
#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject{

    private:
        std::string sub_name;
        int credit;
        std::string teacher;


    public:

        Subject(const std::string& n, int c,  const std::string& t): sub_name{n}, credit{c}, teacher{t} {}
        int getCredit() const {return credit;}



};


#endif
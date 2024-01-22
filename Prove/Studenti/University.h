#ifndef UNIVERSITY_H
#define UNIVERSITY_H


#include "Student.h"
#include <vector>
#include <array>

class University{

    private:
        std::vector<Student> school;
        std::array<int, 181> histogram;


    public:
        University(): school{}, histogram{} {}
        void insertStudent(Student&);
        void buildHisto();
        void printStudent();
        void printHisto();





};


#endif
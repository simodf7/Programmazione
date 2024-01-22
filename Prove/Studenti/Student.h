#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include <iostream>
#include "Subject.h"

class Student{

    private:
        std::string name;
        std::string surname;
        std::string mat;
        std::list<Subject>* exams;


    public: 
        Student(const std::string& n, const std::string& s, const std::string& m): name{n}, surname{s},
        mat{m} { exams = new std::list<Subject>;}
        ~Student(){ delete exams;}
        Student(const Student& s){
            name = s.name;
            surname = s.surname;
            mat = s.name;
            exams = new std::list<Subject>;

            for (auto j = (*s.exams).begin(); j != (*s.exams).end(); j++){
                (*exams).push_back(*j);
            }

        }

        Student& operator=(const Student& s){

            if(this == &s) return *this;

            delete exams;

            name = s.name;
            surname = s.surname;
            mat = s.name;
            exams = new std::list<Subject>;

            for (auto j = (*s.exams).begin(); j != (*s.exams).end(); j++){
                (*exams).push_back(*j);
            }

            return *this;

        }


        int calcCredit(){
            int sum{0};

            for (auto j= (*exams).begin(); j!= (*exams).end(); j++){
                sum += j->getCredit();
            }

            return sum;
        }

        void insertSubject(const Subject& s){
            (*exams).push_back(s);
        }

        void print(){
            std::cout << "\nName: " << name << "\nSurname: " << surname <<
            "\nMatricola: " << mat << "\nCredits: " << calcCredit() 
            << "\n";
        }
        

};


#endif
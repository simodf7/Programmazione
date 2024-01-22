#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <queue>
#include "Patient.h"
#include <iostream>

class Doctor{

    private:    
        std::string name,surname, cell, ssn;
        std::queue<Patient> visits;
    
    public: 
        Doctor(const std::string& n, const std::string& s, const std::string& c, const std::string& sn):
        name{n}, surname{s}, cell{c}, ssn{sn}, visits{} {}
        int getSize() const { return visits.size();}
        const std::string& getName() const {return name;}
        std::queue<Patient>* getQueue()  { 
            std::queue<Patient>* p;
            return p = &visits;
        }

        void print() const {

            std::cout<<"\nName: "<< name <<"\nLastName: "<< surname <<"\nCell: "<< cell <<"\nSSN: "<<ssn << "\n";
            std::cout<<"\nVisits num: "<< getSize() << "\n";          

        }


};


#endif
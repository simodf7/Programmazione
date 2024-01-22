#ifndef ASL_H
#define ASL_H

#include "Doctor.h"
#include <vector>

class Asl{

    private:
        std::vector<Doctor> docs;

    public:
        Asl(): docs{} {}
        void insertDoctor(const Doctor&);
        void insertVisit(const Patient&);
        void eraseVisit(const Patient&);
        void printDoc();
        // bool compare(const Doctor& , const Doctor&);
        
};


#endif
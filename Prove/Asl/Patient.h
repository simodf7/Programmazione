#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient{

    private:
        std::string name,surname,cell, docName;

    public:
        Patient(const std::string& n,const std::string& s, const std::string& c,
        const std::string& d): name{n}, surname{s}, cell{c}, docName{d} {}
        const std::string& getDocName() const {return docName;}


};



#endif

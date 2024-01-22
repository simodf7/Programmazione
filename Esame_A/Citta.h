#ifndef CITTA_H
#define CITTA_H

#include <string>
#include "Paese.h"

class Citta{

    private:
        std::string name;
        int id, abit, ent_coll, usc_coll;
        friend class Paese;

     
    public:
        Citta(int i, const std::string& n, int a): id{i}, name{n}, abit{a}, ent_coll{0}, usc_coll{0} {}
        // int get_ent() const {return ent_coll;}
        // int get_usc() const {return usc_coll;}




};


#endif
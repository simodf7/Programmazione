#ifndef PAESE_H
#define PAESE_H

#include "Citta.h"
#include <vector>

class Paese{

    private:
        int num_citta;
        int id_counter;
        std::vector<Citta> paese;
        float** adiacenza;

    public:
        Paese(int);
        void ins_citta(const std::string&, int);
        void riemp_mat();
        void max_usc_city();
        void max_ent_city();
        void citta_vicina();
        void stampa_grafo();




};

#endif
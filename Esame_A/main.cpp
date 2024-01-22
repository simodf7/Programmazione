#include "Paese.h"

int main(){

    Paese Napoli(4);
    
    Napoli.ins_citta("Pozzuoli", 30000);
    Napoli.ins_citta("Toiano", 2000);
    Napoli.ins_citta("Monteruscello", 1000);
    Napoli.ins_citta("Licola", 2);

    Napoli.riemp_mat();
    Napoli.stampa_grafo();


    Napoli.max_ent_city();
    Napoli.max_usc_city();
    Napoli.citta_vicina();


    return 0;

}
#include "VettoreRilev.h"

int main(){

    VettoreRilev meteo("settimanale");

    meteo.carica_TMax("max.txt");
    meteo.carica_Tmin("min.txt");
    meteo.MedieT();




}
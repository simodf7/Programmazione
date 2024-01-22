#include "Comunita.h"
#include <fstream>
#include <iostream>

Comunita::Comunita(int n): nPersone{n}, persone{} {

    // alloco dinamicamente la matrice, allocando prima un vettore di  n puntatori 
    // e faccio puntare a ogni puntatore un vettore di interi


    adiacenza = new int*[n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            adiacenza[i] = new int[n]{}; // con {} inizializzo ogni elemento a 0




}




Comunita::~Comunita() {

    // dealloco ogni vettore di interi e poi il vettore di puntatori

    for (int i=0; i<nPersone; i++)
        for (int j=0; j< nPersone; j++)
            delete [] adiacenza[i];

    delete [] adiacenza;


}


Comunita::Comunita(const Comunita& c) {

    // copio membro a membro le variabili

    nPersone = c.nPersone;
    persone = c.persone;

    // alloco la matrice come nel costruttore

    adiacenza = new int*[nPersone];

    for (int i=0; i<nPersone; i++)
        for (int j=0; j< nPersone; j++)
            adiacenza[i] = new int[nPersone];
  

    //assegno alla matrice i valori della matrice di adiacenza della comunita c

    for (int i=0; i< c.nPersone; i++)
        for (int j=0; j< c.nPersone; j++)
            adiacenza[i][j] = c.adiacenza[i][j];


}


Comunita& Comunita::operator=(const Comunita& c){


    // stesso procedimento del copy ma prima mi assicuro di non copiare la stessa comunita
    // es. c=c

    if(this == &c) return *this;


    // dealloco la vecchia matrice

    for (int i=0; i<nPersone; i++)
        for (int j=0; j< nPersone; j++)
            delete [] adiacenza[i];

    delete [] adiacenza;

    // assegno le variabili 

    nPersone = c.nPersone;
    persone = c.persone;

    //stesse operazioni del copy constructor a questo punto
    adiacenza = new int*[nPersone];

    for (int i=0; i<nPersone; i++)
        for (int j=0; j< nPersone; j++)
            adiacenza[i] = new int[nPersone];
  



    for (int i=0; i< c.nPersone; i++)
        for (int j=0; j< c.nPersone; j++)
            adiacenza[i][j] = c.adiacenza[i][j];


}


void Comunita::insPersona(const Persona& p){ 
    // inserisco la persona nel vettore
    persone.push_back(p);
}



void Comunita::builtAdiacenza(const std::string& nameFile){

    // apro in lettura il file 

    std::ifstream file(nameFile, std::ios::in);

    if(!file){
        std::cerr << "Il file non è stato aperto correttamente\n";
        exit(EXIT_FAILURE);
    }

    // dichiaro due variabili d'appoggio per leggere nel file

    int i1,i2;

    // leggo fin quando non termina il file e assegno i valori alla matrice di adiacenza 
    // tenendo conto della simmetria

    while(!file.eof()){
        file >> i1;
        file >> i2;
        adiacenza[i1][i2] = 1;
        adiacenza[i2][i1] = 1;
    }

    //chiudo il file

    file.close();



}



void Comunita::printAdiacenza(){

    // stampo la matrice di adiacenza

  for(int i=0; i< nPersone; ++i){
    for(int j=0; j< nPersone; ++j){
       std::cout << adiacenza[i][j] << " ";
    }
    std::cout << "\n";
    }
    
}



void Comunita::mediaEtaAmicizia(){


    // dichiaro due variabili di appoggio
    // sum per effettuare la somma delle eta degli amici della persona i
    // count per effettuare la somma degli amici di i

    float sum{0.0}; // dichiaro float anche sommo int per non fare lo static cast 
    int count{0};
    for(int i=0; i<persone.size(); i++){
        for(int j=0; j<persone.size(); j++){
            if (adiacenza[i][j] == 1 || adiacenza[j][i] == 1){
                sum += persone[j].getEta();
                count++;
            }
        }
        std::cout << "Eta media degli amici di " << persone[i].getName() << " = " << sum/(count) << " anni \n";
        sum = 0.0; // ogni qual volta che determino la media dell'età di una persona prima di passare alla persona successiva
        count = 0; // reinizializzo le variabili a 0
    }


}
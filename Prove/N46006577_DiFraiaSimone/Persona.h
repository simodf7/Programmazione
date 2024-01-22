#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona{

    private:
        int id;
        std::string nome;
        std::string cognome;
        std::string indirizzo;
        int eta;

    public:
        Persona(int, const std::string&, const std::string&, const std::string&, int);
        int getEta() const {return eta;}
        const std::string& getName() const {return nome;}
 



};


#endif
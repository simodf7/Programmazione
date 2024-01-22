#ifndef MOTORE_H
#define MOTORE_H

#include <string>


class Motore{

    private:
        std::string nome;
        std::string marca;
        int posto;

    public:
        Motore(const std::string& n, const std::string& m):nome{n}, marca{m}, posto{-1} {}        
        void setPosto(int p){ posto=p;}
        const std::string& getNome() const {return nome;}
        int getPosto() const {return posto;}

};


#endif
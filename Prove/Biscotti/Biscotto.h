#ifndef BISCOTTO_H
#define BISCOTTO_H

#include <string>
#include <vector>

class Biscotto{

    private:    
        int id;
        std::string name;
        std::string prod;
        std::vector<float> car;

    public:
        Biscotto(int i, const std::string& n, const std::string& p, std::vector<float> c):
        id{i}, name{n}, prod{p}, car{c} {}
        std::vector<float> getCar() const {return car;}
        int getID() const {return id;}







};



#endif
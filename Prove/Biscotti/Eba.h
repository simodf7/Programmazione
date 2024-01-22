#ifndef EBA_H
#define EBA_H

#include <vector>
#include <list>
#include "Biscotto.h"
#include <fstream>
#include <iostream>
#include <cmath>

#define EPSILON 9

class Eba{

    private:
        std::vector<Biscotto> bis;
        std::list<int>* graph;
        int numBiscuit;
        float euclideanDistance(const Biscotto&, const Biscotto&);
        bool checkMarkedList(std::vector<int> , int );

    public: 
        Eba();
        ~Eba();
        void builtGraph();
        void printGraph();
        void cluster(int);
        const int getNum() const {return numBiscuit;}

    //int* p = new int[dim];
    //std::list<int>* p = new std::list<int>[numBiscuit];


};


#endif
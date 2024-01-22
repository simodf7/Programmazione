// web.cpp
#include "Web.h"
#include <list>
#include <iostream>

Web::Web(int n): nPages{n} {
    weblist = new std::list<int>[n];
    for(int i=0; i<n; ++i){
        Page p(i,0, static_cast<double>(1)/n);
        pages.push_back(p);
    }
}


void Web::addLink(int pa, int pb){
    weblist[pa].push_front(pb);
    pages[pa].nLink = pages[pa].nLink +1;
}

void Web::printRanks(){
    for(int i=0; i<nPages; ++i){
        std::cout << "Page[" << i << "]\t ranks: " << pages[i].P << "\n";
    }
    
}

void Web::iteratePageRank(){

    bool convergence{false};
    double diff{0};
    double* prev = new double[nPages];

    while(!convergence){

        for(int i=0; i<nPages; ++i){
            prev[i] = pages[i].P;
        }

        pageRank();

        for(int i=0; i<nPages; ++i){
            diff += (prev[i]-pages[i].P) * (prev[i]-pages[i].P);
        }
        

        std::cout << "Difference is " << diff << "\n";

        if(diff< 1e-20){
            convergence = true;
        }

        diff = 0; 
    }
    

    delete[] prev;
}


void Web::pageRank(){

    double* newP = new double[nPages];
    for(int i=0; i<nPages; ++i){
        for(auto j = weblist[i].begin(); j != weblist[i].end(); ++j){
            newP[*j] += (pages[i].P)/(pages[i].nLink);
        }
    }

    for(int i=0; i<nPages; ++i){
        pages[i].P = (static_cast<double>(1) - delta)/nPages + delta*newP[i];
    }

    delete[] newP;
}




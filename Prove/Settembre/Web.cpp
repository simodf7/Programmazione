#include "Web.h"
#include <iostream>
#include <cmath>

void Web::insertPage(){
    
    //std::cout << "c";
    float s = static_cast<float>(1)/numPage;
    std::cout << numPage << "\n";
    //std::cout << "d";
    for(int i=0; i<numPage;i++){
        pages.push_back(new Page(i, s));
        std::cout << "Pagina assegnata: " << i << "\n"; 
    }
    
}

//void Web::setPage(int i){ numPage = i;}

void Web::addlinks(int i, int s){

    web[i].push_back(s);
    (pages[i]->link)++;
    
}

void Web::printRanks(){

    for (int i=0; i<numPage; i++){
        std::cout << "P[" << i << "]= " << pages[i]->rank << "\n";
    }

    
}

void Web::iterateRanks(){

    bool conv{false};
    float* p = new float[numPage]{};
    float diff{0.0};
    int n{0};


    while(!conv){

        for (int i=0; i<numPage; i++){
            p[i] = pages[i]->rank;
        }

        rankUpdate();

        for (int i=0; i<numPage; i++){
            diff += (p[i] - pages[i]->rank)*(p[i] - pages[i]->rank);
        }
        
        std::cout << "Difference is: " << diff << "\n"; 

        if(diff < 2e-10){
            conv = true;
        }

        n++;


        diff = 0;



    }



    std::cout << n <<"\n";

    delete[] p;
    
}


void Web::rankUpdate(){

    // float r = (1-delta)/numPage;

    float* p = new float[numPage]{};
   


    for (int i=0; i<numPage; i++){
        for(auto j = (web[i].begin()); j != (web[i].end()); j++){
            // if ((*j)!= i){
                //std::cout << "Rank " << (*j) << ": " << p[(*j)] << "\n";
                p[(*j)] += ((delta)*(pages[i]->rank))/pages[i]->link;
                //pages[(*j)]->rank += ((delta)*(pages[i]->rank))/pages[i]->link;
                //std::cout << "Rank " << (*j) << ": " << p[(*j)] << "\n";
            //}
        }
    }

    for (int i=0; i<numPage; i++){
        pages[i]->rank = ((1-delta)/numPage) + p[i];
    }


    delete[] p;


    
}

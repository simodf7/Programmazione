#include "Paese.h"
#include <fstream>
#include <iostream>

Paese::Paese(int n): num_citta{n}, id_counter{0}{

    adiacenza = new float*[num_citta];
    for(int i=0;i<num_citta;i++){
        adiacenza[i] = new float[num_citta]{}; //Inizializzo tutti gli elementi della matrice a 0    
    }


}


void Paese::ins_citta(const std::string& n , int a){

    if (id_counter == num_citta){return;}    
    paese.push_back(Citta(id_counter, n,a));
    id_counter++;
    
}

void Paese::riemp_mat(){

    std::ifstream f{"roads.txt"};

    if(!f){
        std::cerr << "File could not be opened "; 
        exit(EXIT_FAILURE);
    }

    int c1,c2;
    float d;

    while(!f.eof()){
        f >> c1;
        f >> c2;
        f >> d;
        adiacenza[c1][c2] = d;
        paese[c1].usc_coll++;
        paese[c2].ent_coll++;
    }

    f.close();

    
}


void Paese::max_usc_city(){

    int max = paese[0].usc_coll;
    int id_max;
    for(int i=0; i<paese.size(); i++){
        if(paese[i].usc_coll > max){
            max = paese[i].usc_coll;
            id_max = i;
        }
    }

    std::cout << "La citta con piu collegamenti uscenti e' " << paese[id_max].name << "\n";

}

void Paese::max_ent_city(){


    int max = paese[0].ent_coll;
    int id_max;
    for(int i=0; i<paese.size(); i++){
        if(paese[i].ent_coll > max){
            max = paese[i].ent_coll;
            id_max = i;
        }
    }

    std::cout << "La citta con piu collegamenti entranti e' " << paese[id_max].name << "\n";

}

void Paese::citta_vicina(){

    float min{0.0};
    int id_min;

    for(int i=0; i< num_citta; i++){
        min = adiacenza[i][0];
        id_min = 0;
        for(int j=0; j<num_citta; j++){
            if(min == 0){
                min = adiacenza[i][j];
                id_min = j;
                continue;
            }
            if (adiacenza[i][j] < min && adiacenza[i][j] != 0) {
                min = adiacenza[i][j];
                id_min = j;
            }
        }
        std::cout << "La citta " << paese[i].name << " e' piu vicina alla citta " << paese[id_min].name << "\n";
    }
    
}

void Paese::stampa_grafo(){

    for(int i=0; i<num_citta; i++){
        for(int j=0; j< num_citta; j++){
            std::cout << adiacenza[i][j] << " ";
        }
        std::cout << "\n";
    }
    
}
    
#include "Cinema.h"


void Cinema::insertFilm(const std::string& f){

    for(auto j = films.begin(); j != films.end(); j++){
        if(f < (*j)){
            films.insert(j,f);
            break;
        }
    }

    films.push_back(f);
    
}

void Cinema::removeFilm(const std::string& f){

    for(auto j = films.begin(); j != films.end(); j++){
        if(f == (*j)){
            films.erase(j);
            break;
        }
    }
    
}

void Cinema::watchFilm(const std::string& f){

    system();
    
    
}





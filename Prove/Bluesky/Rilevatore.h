#ifndef RILEVATORE_H
#define RILEVATORE_H


#include <list>
#include "Rilevamento.h"

class Rilevatore{

    private:

        int id_station;
        int coord_X;
        int coord_Y;
        std::list<Rilevamento>* rilevamenti;

    public:
        Rilevatore(int i, int x, int y): id_station{i}, coord_X{x}, coord_Y{y}, rilevamenti{} {
            rilevamenti = new std::list<Rilevamento>;
           // *rilevamenti = {};
        }
        ~Rilevatore(){delete rilevamenti;}
        Rilevatore(const Rilevatore& r){

            id_station = r.id_station;
            coord_X = r.coord_X;
            coord_Y = r.coord_Y;
            rilevamenti = new std::list<Rilevamento>;

            for(auto j = (*r.rilevamenti).begin(); j!= (*r.rilevamenti).end(); j++){
                rilevamenti->push_back(*j);
            }

        }


        Rilevatore& operator=(const Rilevatore& r){

            if(this == &r) return *this;

            delete rilevamenti;

            id_station = r.id_station;
            coord_X = r.coord_X;
            coord_Y = r.coord_Y;
            rilevamenti = new std::list<Rilevamento>;

            for(auto j = (*r.rilevamenti).begin(); j!= (*r.rilevamenti).end(); j++){
                rilevamenti->push_back(*j);
            }

        }
        

        int getID() const {return id_station;}
        int getX() const {return coord_X;}
        int getY() const {return coord_Y;}
        std::list<Rilevamento>* getRelList() const {return rilevamenti;}
        //std::list<Rilevamento> getRelList() const {return rilevamenti;}



};


#endif
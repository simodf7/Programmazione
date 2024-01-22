#ifndef CINEMA_H
#define CINEMA_H

#include <list>
#include <string>

class Cinema{

    private:
        std::list<const std::string&> films;


    public:
        Cinema(): films{} {};
        void insertFilm(const std::string&);
        void removeFilm(const std::string&);
        void watchFilm(const std::string&);



};


#endif
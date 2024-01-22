#ifndef IMMAGINE_H
#define IMMAGINE_H

#include <string>

class Immagine{

    private:
        float** mat;
        int row;
        int col;
        float filter(int,int);

    public:
        Immagine(int=3,int=3);
        ~Immagine();
        Immagine(const Immagine&);
        Immagine& operator=(const Immagine&);
        Immagine insFilter();
        void printMat();
        void riempMat();
        int getRow() const {return row;}
        int getCol() const {return col;}



};

#endif
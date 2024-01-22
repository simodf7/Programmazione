#ifndef PAPERARTICLE_H
#define PAPERARTICLE_H

#include "Publication.h"


class PaperArticle: public Publication {

public:

    static int nPapArt;
    PaperArticle(std::string, std::vector<std::string> , int, std::string, int, int, int);
    ~PaperArticle();

    // member functions
    std::string toString();


    // set Functions 
    PaperArticle& setTitleArt(std::string);
    PaperArticle& setNumArt(int);
    PaperArticle& setPageIni(int);
    PaperArticle& setPageFin(int);

    // get Functions
    
    std::string getTitleArt() const;
    int getNumArt() const;
    int getPageIni() const;
    int getPageFin() const;


 
private:

    std::string titleArt;
    int numArt;
    int pageIni;
    int pageFin;

};


#endif
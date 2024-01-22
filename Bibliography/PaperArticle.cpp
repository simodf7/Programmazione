#include "PaperArticle.h"
#include <sstream>

PaperArticle::PaperArticle (std::string title, std::vector<std::string> authors, int year,std::string titleArt, int numArt, 
int pageIni, int pageFin): Publication(title, authors, year){

    this->titleArt = titleArt;
    this->numArt = numArt;
    this->pageIni = pageIni;
    this->pageFin = pageFin;
    ++nPapArt;

}

PaperArticle::~PaperArticle(){
    --nPapArt;
}



PaperArticle& PaperArticle::setTitleArt(std::string t){
    titleArt = t;
    return *this;
}


PaperArticle& PaperArticle::setNumArt(int n){
    numArt = n;
    return *this;

}

PaperArticle& PaperArticle::setPageIni(int pi){
    pageIni = pi;
    return *this;
}


PaperArticle& PaperArticle::setPageFin(int pf){
    pageFin = pf;
    return *this;
}



std::string PaperArticle::getTitleArt() const{
    return titleArt;
}


int PaperArticle::getNumArt() const{
    return numArt;
}

int PaperArticle::getPageIni() const{
    return pageIni;
}

int PaperArticle::getPageFin() const{
    return pageFin;
}



std::string PaperArticle::toString(){

    std::ostringstream out;
    out << Publication::toString() << " " << "('" << titleArt << "', num: " << numArt << 
    ", pp: " << pageIni << ", " << pageFin << ").";
    return out.str();

}
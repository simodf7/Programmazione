#include "PaperConf.h"
#include <sstream>

PaperConf::PaperConf(std::string title, std::vector<std::string> authors, int year,std::string titleConf, std::string locatConf, int page ):
Publication(title, authors, year){

    this->titleConf = titleConf;
    this->locatConf = locatConf;
    this->page = page;
    nPapConf++;
}



PaperConf::~PaperConf(){
    --nPapConf;
}


PaperConf& PaperConf::setTitleConf(std::string t){
    titleConf = t;
    return *this;
}

PaperConf& PaperConf::setlocatConf(std::string l){
    locatConf = l;
    return *this;
}


PaperConf& PaperConf::setPage(int p){
    page = p;
    return *this;
}



std::string PaperConf::getTitleConf() const{
    return titleConf;
}

std::string PaperConf::getLocatConf() const{
    return locatConf;
}

int PaperConf::getPage() const{
    return page;
}



std::string PaperConf::toString(){

    std::ostringstream out;
    out << Publication::toString() << " transcription of: " << titleConf << ", " << locatConf << ", page: " << page << ".";
    return out.str();

}
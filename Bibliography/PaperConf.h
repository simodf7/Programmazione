#ifndef PAPERCONF_H
#define PAPERCONF_H

#include "Publication.h"


class PaperConf: public Publication {


public:

    static int nPapConf;
    PaperConf (std::string, std::vector<std::string>, int, std::string, std::string, int);
    ~PaperConf();


    //member functions
    std::string toString();

    // set functions
    PaperConf& setTitleConf(std::string);
    PaperConf& setlocatConf(std::string);
    PaperConf& setPage(int);

    // get functions

    std::string getTitleConf() const;
    std::string getLocatConf() const;
    int getPage() const;



private: 
    std::string titleConf;
    std::string locatConf;
    int page;    
};

#endif
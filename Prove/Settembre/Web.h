#ifndef WEB_H
#define WEB_H

#include <list>
#include <vector>
#include "Page.h"


class Web{

    private:
        int numPage;
        std::vector<Page*> pages;
        std::list<int>* web;
        //friend class Page;
        float delta{0.01};
        //float eps{};
        //void checkConv();

    public: 
        Web(int i): numPage{i}, pages{} {web = new std::list<int>[numPage];}
        void insertPage();
        void rankUpdate();
        void setPage(int);
        void addlinks(int,int);
        void printRanks();
        void iterateRanks();
};


#endif

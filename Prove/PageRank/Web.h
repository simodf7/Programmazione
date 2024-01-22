#ifndef WEB_H
#define WEB_H


#include <vector>
#include <string>
#include <list>

class Web{

    public:
        class Page{
            private:
                int pageId;
                int nLink;
                double P;   //ranl
                friend class Web;
            public:
                Page(int id, int nl, double p): pageId{id}, nLink{nl}, P{p} {};
        };
        Web(int);
        void pageRank();
        void addLink(int,int);
        void printRanks();
        void iteratePageRank();

    private:
        int nPages;
        std::vector<Page> pages;
        std::list<int>* weblist;
        double delta{0.01};


};


#endif
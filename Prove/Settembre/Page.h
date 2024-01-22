#ifndef PAGE_H
#define PAGE_H


class Page{

    private:
        int id;
        int link;
        float rank;
        //int numPage;
        friend class Web;

    public:
        Page(int i, float r): id{i}, link{0}, rank{r} {}
       // void setRank(float r) {rank = r;}



};



#endif
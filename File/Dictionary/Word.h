#ifndef WORD_H
#define WORD_H

#include <string>


class Word{


    // friend std::ostream &operator<<(std::ostream & out, Word& w){
    //     w.print(out);
    //     return out;
    // }


    private:
        std::string engWord;
        std::string itaWord;

    public:
        Word(const std::string& e, const std::string& i): engWord(e), itaWord{i} {}
        std::string getEng() const {return engWord;}
        std::string getIta() const {return itaWord;}
        std::string toString() {   
            std::string out; 
            out =  getEng() + "-" + getIta() + "\n";
            return out;
        }
    




};


#endif
#ifndef DICT_H
#define DICT_H

#include "Word.h"
#include <vector>
#include <fstream>
#include <iostream>

class Dict{

    private:
        std::vector<Word> words;
        std::string dictFileName;


    public:
        Dict(const std::string& n): dictFileName{n}, words{} {}
        std::string searchWord(const std::string& w);
        void addWord(const std::string& e, const std::string& i);
        void loadDictionary();
        void writeDictionary();
        void printDictionary();
        //bool wordInDict(const std::string& w);





};


#endif
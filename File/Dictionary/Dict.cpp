#include "Dict.h"

void Dict::loadDictionary(){

    std::string eng,ita;

    std::ifstream file{dictFileName, std::ios::in};
    if(!file){
        std::cerr << "Dictionary cannot be opened\n";
        exit(EXIT_FAILURE);
    }

    while(file >> eng >> ita){
        words.push_back(Word{eng,ita});
    }

    file.close();

}




void Dict::addWord(const std::string& e, const std::string& i){

    Word w(e,i);
    words.push_back(w);

}



std::string Dict::searchWord(const std::string& w){

    bool found{false};
    std::string itWord;
    Word wd{"", ""};

    for(auto j = words.begin(); j != words.end(); j++){
        wd = (*j);
        if( wd.getEng() == w){
            found = true;
            itWord = wd.getIta();
            break;
        }
    }

    return { (found == true) ? itWord : ""};


}   




void Dict::writeDictionary(){

    std::fstream file{dictFileName, std::ios::app};
    if(!file){
        std::cerr << "Dictionary cannot be opened\n";
        exit(EXIT_FAILURE);
    }

    for(auto j = words.begin(); j != words.end(); j++){
            file << (*j).toString() << "\n";
    }

    file.close();

}


void Dict::printDictionary(){

    for(auto j = words.begin(); j != words.end(); j++){
        std::cout << (*j).toString() << "\n";
    }
}    



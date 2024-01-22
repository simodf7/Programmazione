#include "Dict.h"
#include <iostream>

using std::cout; using std::cin;
int menu();

int main(){

    Dict dictionary("eng_it.dict");
    dictionary.loadDictionary();
    
    cout << "Welcome to English-Italian Dictionary\n";
    bool cond{true};
    int request;
    std::string word;
    std::string itWord;

    while((cond)){

        switch(request = menu()){
        case 1: 
            cout << "Enter the English word you want to search: "; cin >> word;
            itWord = dictionary.searchWord(word);

            if(itWord == "") cout << "Word not Found \n\n";
            else cout << word << " means " << itWord << "\n\n"; 
            break;
        
        case 2:
            cout << "Enter the English word: "; cin >> word;
            cout << "Enter the Italian translation: "; cin >> itWord;

            dictionary.addWord(word,itWord);
            cout << "Word inserted\n\n"; 
            break;

        case 3:
            dictionary.printDictionary();
            cout << "\n\n";
            break;

        case 4:
            dictionary.writeDictionary();
            cond = false;
            cout << "\n\n";
            break;

        default:
            std::cerr<<"\n Errore: Scelta non discponibile";
            break;
        
        }

    }




};



int menu (){

    int n;
    cout << " 1 - Search \n";
    cout << " 2 - Add a word \n";
    cout << " 3 - View Dictionary \n";
    cout << " 4 - Exit program \n";

    cout << "Insert your choice: "; cin >> n;
    cout << "\n";
    return n;
};
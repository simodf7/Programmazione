#include "Publication.h"
#include "Book.h"
#include "PaperArticle.h"
#include "PaperConf.h"
#include <iostream>
#include <vector>
//#include <algorithm>
#include "quicksort.h"

using std::cout;

bool comparePubsPtr(Publication* A, Publication* B) { return *A<*B ;};

int Publication::nGenPub = 0;
int Book::nBooks = 0;
int PaperArticle::nPapArt = 0;
int PaperConf::nPapConf = 0;

int main(){

    std::vector <Publication*> bib;

    bib.push_back(new Publication( "A Great Book", {"Antonio Strafazzi" , "Michele Rovazzi"}, 2001));
    bib.push_back(new Book("Introduction to Computer Algotihms", {"Alfonso Giuvinotto", "Michele Costantino"},1974, "Zanichelli", 9606069));
    bib.push_back(new PaperArticle( "Arte di costruire occhiali", {"Mino Ostrica", "Giovanni Senzocchio", "Alfonso Trippa"},2450, "Eyes", 15, 456, 458));
    bib.push_back(new PaperConf("Zappa", {"Frank Licola", "Tonino Varcaturo"}, 2016, "Conferenza sull'importanza della zappa", "Londra", 45));
    bib.push_back(new Book("Gaviscon", {"Frank Stomaco"}, 1988 , "Intestino edizioni", 9655959));

    //std::sort(bib.begin(), bib.end(), comparePubsPtr);
    
    
    for(int i=0; i<bib.size(); i++){
        cout << "/Debug: " << bib[i] << "\n";
    }

    cout << "\n";


    quickSort (bib, 0, bib.size()-1);


    for(int i=0; i<bib.size(); i++){
        cout << "/Debug: " << bib[i] << "\n";
    }

    cout << "\n";


    for(int i=0; i<bib.size(); i++){
        cout << bib[i]->toString() << "\n";
    }

    cout << "\n";
    cout << "Number of Generic Publications: " << Publication::nGenPub - Book::nBooks - PaperArticle::nPapArt - PaperConf::nPapConf<< "\n";
    cout << "Number of Books: " << Book::nBooks << "\n";
    cout << "Number of Paper Articles: " << PaperArticle::nPapArt << "\n";
    cout << "Number of Papers from Conferences: " << PaperConf::nPapConf << "\n";
    



    return 0;
}


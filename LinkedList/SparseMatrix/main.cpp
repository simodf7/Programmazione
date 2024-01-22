#include "MatrixList.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::vector; using std::string;
using std::ifstream; using std::cerr;


int main(int argc, char** argv){

    string filename = argv[1];
    ifstream file(filename);
    
    if(!file){
        cerr << "File could not be opened";
        exit(EXIT_FAILURE);
    }


    int r; 
    int c;
    int s[r*c];

    while(!file.eof()){
        file >> r;
        file >> c;
        for(int i=0; i<r*c -1 ; ++i){
            file >> s[i];
        }
    }













}
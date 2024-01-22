#include "Maze.h"
#include <iostream>
#include <fstream>



using std::ifstream;
using std::cerr;
using std::cout;
using std::ios;


int main(){

    ifstream file;
    file.open("Mat.txt", ios::in);

    if(!file){
        cerr << "File could not be opened";
        exit(EXIT_FAILURE);
    }


    int r;
    int c;
    int** grid;

    
    file >> r;
    file >> c;
    
    grid = new int*[r];
    for(int i=0; i<r; ++i){
        grid[i] = new int[c];
    }

    while(!file.eof()){

        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                file >> grid[i][j];
            }
        }
    
    }


    Maze m(r,c,grid);

    if(m.traverseRec(0,0)){
        cout << "Sei arrivato all'uscita!! \n"; 
    }
    else cout << "Non Sei arrivato all'uscita :( \n"; 

    cout << m.toString();


}
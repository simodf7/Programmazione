#ifndef MAZE_H
#define MAZE_H

#include "LStack.h"

class Maze{

    private:
        int nrow;
        int ncol; 
        int** maze;
        const int TRIED{4};
        const int PATH{5};
        int move[8][2] = { {-1,0},
                           {-1,1},
                           {0,1},
                           {1,0},
                           {1,1},
                           {1,-1},
                           {0,-1},
                           {-1,-1},
        };
    
    public:
        Maze(int, int, int**);
        bool traverse();
        bool traverseRec(int,int);
        bool rTraverse(int, int);
        std::string toString();
        bool valid(int,int);        



};


#endif
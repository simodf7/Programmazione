#include "Maze.h"
#include "Position.h"
#include "LSTack.h"

Maze::Maze(int nr, int nc, int** grid): nrow{nr}, ncol{nc} {

    maze = new int*[nrow];
    
    for(int i=0; i<nrow; ++i)
        maze[i] = new int[ncol];

    for(int i=0; i<nrow; ++i){
        for(int j=0; j< ncol; ++j){
            maze[i][j] = grid [i][j];
        }
    }
    
}

bool Maze::traverse(){


    bool done{false}; // variabile che ci dice quando siamo arrivati all'uscita
    LinkedStack<Position> s;  // stack per salvare le posizioni
    Position p_int (0,0,0); // posizione 
    s.push(p_int); // salvo nello stack la posizione 

    while(!s.empty()){

        Position p(s.top());  // impongo la posizione dalla cima dello stack {che include la prossima mossa}
        s.pop();  //  faccio il pop dell'elemento dalla cima
        int dir = p.dir; // come anticipato salvo la prossima mossa (che prendo da p) e la salvo in una variabile
        
        while(dir<8){  // ho a disposizione solo 8 mosse possibili

            int row = p.x + move[dir][0];  // nuova x = vecchia x + mossa (delta x)
            int col = p.y + move[dir][1];  // nuova y = vecchia y + mossa (delta y)
            
            // check victory
            if (row == (nrow-1) && col == ncol-1 && valid(row,col)){
                s.push(Position(row, col, dir));
                maze[p.x][p.y] = PATH;
                while(!s.empty()){
                    Position pp(s.top());
                    s.pop();
                    maze[pp.x][pp.y] = PATH;
                }

                done = true;
                return done;  // vittoria
            }  
            
            if(valid(row, col)){ // check valid move
                maze[row][col] = TRIED;  // marco la posizione cosi so se ci sono passato (non ci posso ripassare)
                p.dir = dir+1; // se dovessi tornare in questa posizione non prendo questa direzione ma la successiva
                s.push(p);
                dir = 0; // riporto a 0 dir per la prossima posizione
                p.x = row;
                p.y = col;
            }
            else dir++;

        }
    }

    return done;


}





bool Maze::traverseRec(int x,int y){  // same function using stack implicitly through recursive function
    
    maze[0][0] = PATH;
    bool done{false};
    int dir;
    dir=0;
    while(dir<8){

        int row = x + move[dir][0];
        int col = y + move[dir][1];

        if (row == (nrow-1) && col == ncol-1 && valid(row,col)){
                done = true;
                maze[x][y] = PATH;
                return done;  // vittoria
        }  

        if(valid(row,col)){
            maze[row][col] = TRIED;
            done = traverseRec(row,col);
            if (done){
                maze[row][col] = PATH;
                return done;
            }
        }
        else dir++;
    }
    
    return done;
}



bool Maze::rTraverse(int x, int y){ // alternative implementation

    

    if(valid(x,y)){
        return false;
    }

    if(x == nrow-1 && y == ncol-1){
        return true;
    }

    for(int dir=0; dir< 8 ; ++dir){
        if(rTraverse(x+move[dir][0], y+move[dir][1])){
            maze[x][y] = PATH;
            return true;
        }
    }


}



std::string Maze::toString(){

    std::string result{"\n"};
    for (int row = 0; row < nrow; row++){
        for (int col = 0; col < ncol; col++){
            if (maze[row][col]==PATH){
                result+="P";
            }
            else if(maze[row][col]==TRIED)
                result+="T";
            else
                result+="0";
        }
        result+="\n";  
    }
    
    return result;   
}

bool Maze::valid(int x, int y){
    if(x>0 && x<nrow && y>0 && y<nrow){
        if(maze[x][y] == 0){
            std::cout << "Row: " << x << ", Col: " << y << "\n";
            return true;
        }
    }

    return false;

    
}







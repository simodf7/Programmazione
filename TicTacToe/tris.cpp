#include "tris.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


TicTacToe::TicTacToe (){
    for (int i=0; i<3; ++i)
        for (int j=0; j<3; ++j){
            board[i][j] = ' ';
        }
}


void TicTacToe::printBoard() const{

    cout <<"   0   1   2\n\n";
    for(int r{0}; r<3; ++r){
        cout <<r;
        for(int c{0}; c<3; ++c){
            cout <<setw(3) << static_cast<char>(board[r][c]);
            if(c!=2) cout <<"|";
        }
        if(r!=2) cout <<"\n ___|___|___\n    |   |    \n";
    }
    cout <<"\n\n";
}


TicTacToe::Status TicTacToe::gameStatus() const{

    // check per vittoria su diagonale

    if (board[0][0] != ' ' && board[0][0] == board [1][1] && board[0][0]==board[2][2]){
        return WIN;
    }
    else if (board[0][2] != ' ' && board[0][2] == board [1][1] && board[0][2]==board[2][0]){
        return WIN;
    }


    // check vittoria riga

    for (int i=0; i<3; ++i){
        if (board[i][0] != ' ' && board[i][0] == board [i][1] && board[i][0]==board[i][2])
            return WIN;
    }


    // check vittoria colonna

    for (int j=0; j<3; ++j){
        if (board[0][j] != ' ' && board[0][j] == board [1][j] && board[0][j]==board[2][j])
            return WIN;
    }


    // Se non trovo vittoria controllo se ho finito le caselle

    for ( int i=0; i<3; ++i)
        for(int j=0; j<3; ++j){
            if (board[i][j] == ' ')
                return CONTINUE;
        }


    // se le caselle sono piene allora pareggio 

    return DRAW;

}


bool TicTacToe::checkMove(int x, int y) const{
    if (board[x][y] == ' ' && (x >=0 && x <=2 ) && (y >=0 && y <=2 ))
        return false;
}




bool TicTacToe::move(int symbol){
    printBoard();

    int x,y;

    do{
        cout << "Player " << static_cast<char>(symbol)<<  " make your move: " ;
        cin >> x >> y; 
        cout << endl;
    }while(checkMove(x,y));

    board[x][y] = symbol;
    printBoard();
    Status match = gameStatus();
     
    if (match == WIN){
        cout << "Player " << static_cast<char>(symbol) << " WINS !! \n";
        return true;
    }
    else if (match == DRAW){
        cout << "It's a DRAW !! \n";
        return true;
    }
    else{ // continue
        return false;
    }

}


void TicTacToe::matchPlay(){
    //alterniamo i vari turni

    while (true){
        if (move('X')){
            break;
        }
        else if (move('O'))
            break;
    }
}
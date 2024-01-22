#ifndef TRIS_H
#define TRIS_H

class TicTacToe{

private:
    enum Status {WIN, DRAW, CONTINUE};
    int board[3][3];

public:
    TicTacToe();
    void printBoard() const;
    bool move(int);
    bool checkMove(int, int) const;
    void matchPlay();
    Status gameStatus() const;

};




#endif
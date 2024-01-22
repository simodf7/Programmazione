#ifndef POSITION_H
#define POSITION_H

class Position{
    public:
        Position(int px=0, int py=0, int pdir=0): x{px}, y{py}, dir{pdir}{};
        friend class Maze; // le funzioni di maze devono poter accedere a x, y, dir
    private:
        int x;
        int y;
        int dir;
};

#endif
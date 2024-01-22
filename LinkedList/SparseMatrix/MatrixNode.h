#ifndef MATRIXNODE_H
#define MATRIXNODE_H


class MatrixNode{
    private:
        int x;
        int y;
        int elem;
        MatrixNode* next;
        friend class MatrixList;

};

#endif
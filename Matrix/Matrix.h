#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{

    friend Matrix operator+ (const Matrix &, const Matrix &);
    friend Matrix operator- (const Matrix &, const Matrix &);
    friend Matrix operator* (const Matrix &, const Matrix &);
    friend std::ostream &operator<<(std::ostream &, const Matrix&);

private: 

    int row;
    int col;
    double** mat;

public:
    
    Matrix(int, int); // default constructor
    Matrix(const Matrix&); // copy constructor
    ~Matrix(); // destructor


    Matrix& setMat(double, int, int);
    double getValue(int, int) const;
    int getRow() const;
    int getCol() const;
    void printMat(std::ostream &) const;

};


#endif
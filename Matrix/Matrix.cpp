#include <iostream>
#include <stdexcept>
#include "Matrix.h"

Matrix operator+(const Matrix &m1, const Matrix &m2){
    
  if((m1.row != m2.row) || (m1.col != m2.col)){

    throw std::invalid_argument("You can sum two matrix only if the dimentions are the same");
  }


  Matrix m3(m1.row, m1.col);

    for(int i=0; i<m1.row; ++i)
      for(int j=0; j<m1.col; ++j){
        m3.setMat((m1.getValue(i,j)+m2.getValue(i,j)),i,j);
      }
  return m3;
  

}


Matrix operator-(const Matrix &m1, const Matrix &m2){
    
  if((m1.row != m2.row) || (m1.col != m2.col)){

    throw std::invalid_argument("You can substract two matrix only if the dimentions are the same");
  }


  Matrix m3(m1.row, m1.col);

    for(int i=0; i<m1.row; ++i)
      for(int j=0; j<m1.col; ++j){
        m3.setMat((m1.getValue(i,j)-m2.getValue(i,j)),i,j);
      }
  return m3;
  
}



Matrix operator*(const Matrix &m1, const Matrix &m2){

  if(m1.col != m2.row){

    throw std::invalid_argument("You can multiply two matrix only m1 col == m2 row");
  }


  Matrix m3(m1.row, m2.col);

  double sum{0};
  for(int j=0; j<m2.row; ++j){
    for(int t=0; t<m2.col; ++t){
      for(int i=0; i<m1.col; ++i){
        sum += ((m1.getValue(j,i))*(m2.getValue(i,t)));
      }
      m3.setMat(sum,j,t);
      sum=0;
    }
  }

  return m3;


}




std::ostream& operator<<(std::ostream &out, const Matrix& m){

  m.printMat(out);
  return out;

}




// default
Matrix::Matrix(int row, int col){

  this->row = row;
  this->col = col;
  

  mat = new double*[row];
  for (int i=0; i<row; i++)
    for (int j=0; j<col; j++)
      mat[i] = new double[col]{}; // con {} inizializzo ogni elemento a 0

}



Matrix::Matrix(const Matrix& m){

  row = m.row;
  col = m.col;

  mat = new double*[row];

  for (int i=0; i<row; i++)
    for (int j=0; j< col; j++)
          mat[i] = new double[col];
  

  for (int i=0; i<m.row; i++)
    for (int j=0; j< m.col; j++)
          mat[i][j] = m.mat[i][j];

    
}


Matrix::~Matrix(){

  for (int i=0; i<row; i++)
    for (int j=0; j< col; j++)
          delete [] mat[i];

  delete [] mat;
}



Matrix& Matrix::setMat(double v, int row, int col){

  mat[row][col] = v;
  return *this;

}



double Matrix::getValue(int row, int col) const{
  return mat[row][col];
}


void Matrix::printMat(std::ostream &out) const {

  for(int i=0; i< row; ++i){
    for(int j=0; j<col; ++j){
      out << mat[i][j] << " ";
    }
    out << "\n";
  }
    
}

int Matrix::getRow() const{
  return row;
}

int Matrix::getCol() const{
  return col;
}
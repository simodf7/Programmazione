#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

int main(){
    

    Matrix m1(3,3);
    Matrix m2(2,3);



    srand(1); //per passare da un double ad un int, abbiamo bisogno di uno static cast

    for(int i=0;i<m1.getRow();i++){
        for(int j=0;j<m1.getCol();j++){
            m1.setMat(1.1,i,j);
            //rand()%100 è un numero intero compreso tra 0 e 99. Diviso 100 da un numero compreso tra 0 e .0.99;
            //ho dovuto fare uno static cast perchè altrimenti avrei ottenuto sempre 0
        }
    }


    for(int i=0;i<m2.getRow();i++){
        for(int j=0;j<m2.getCol();j++){
            m2.setMat(2.2,i,j);
            //rand()%100 è un numero intero compreso tra 0 e 99. Diviso 100 da un numero compreso tra 0 e .0.99;
            //ho dovuto fare uno static cast perchè altrimenti avrei ottenuto sempre 0
        }
    }


    cout<<"\nMatrix m1 is: \n" << m1;
    cout<<"\nMatrix m2 is: \n"<< m2;

    Matrix m3 = m1 + m2;

    cout << "\nm1+m2: \n" << m3;

    Matrix m4 = m1 - m2;

    cout << "\nm1-m2: \n" << m4;
    
    Matrix m5 = m1*m2;

    cout << "\nm1*m2: \n" << m5;

}

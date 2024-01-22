#include <iostream>
#include "point.h"
#include "rectangle.h"




Rectangle::Rectangle (Point p1, Point p2, Point p3, Point p4){
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
}


Rectangle:: ~Rectangle (){};

void Rectangle::setP1(Point p1){
    this->p1 = p1;
}

void Rectangle::setP2(Point p2){
    this->p2 = p2;
}

void Rectangle::setP3(Point p3){
    this->p3 = p3;
}

void Rectangle::setP4(Point p4){
    this->p4 = p4;
}



Point Rectangle::getP1() const{
    return p1;
}


Point Rectangle::getP2() const{
    return p2;
}

Point Rectangle::getP3() const{
    return p3;
}

Point Rectangle::getP4() const{
    return p4;
}



int Rectangle::rectHeight() const{
    return (p3.getY() - p1.getY());
}

int Rectangle::rectWidth() const{
    return (p2.getX() - p1.getX());
}


int Rectangle::rectPerimeter() const{
    return 2*rectWidth() + 2*rectHeight();
}

int Rectangle::rectArea() const{
    return rectWidth()*rectHeight();
}



void Rectangle::drawRect(){
    int r=25;
    int c=25;

    char** mat = new char*[r];
	for (int i=0; i<r; i++)
	   for (int j=0; j<c; j++)
	      mat[i] = new char[c];


   for (int i = 0 ; i < r; ++i){
    for (int j = 0; j < c; ++j){
        if (j < p1.getX() || i < p2.getY() || i > p3.getY() || j>p2.getX() ){
            mat[i][j] = '.';
        }
        else if ( ( j>p1.getX() && j<p2.getX() )  && ( i>p1.getY() && i<p3.getY() ) ){
            mat[i][j] = '-';
        }
        else mat[i][j] = '*'; 
    }
   }

    for (int i = 0 ; i < r; ++i){
        for (int j = 0; j < c; ++j){
            std::cout << mat[i][j] << " "; 
        }
        std::cout <<"\n";
    }


    for (int i = 0; i < r; ++i)
    	delete [] mat[i];
	delete [] mat;

}
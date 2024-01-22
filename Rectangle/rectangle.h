#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle{
public:

    Rectangle (Point , Point , Point , Point );
    ~Rectangle();


    //set Functions

    void setP1(Point); 
    void setP2(Point); 
    void setP3(Point); 
    void setP4(Point); 


    //get Functions

    Point getP1() const;
    Point getP2() const;
    Point getP3() const;
    Point getP4() const;


    // member functions

    int rectArea() const;
    int rectWidth() const;
    int rectHeight() const;
    int rectPerimeter() const;
    void drawRect();




private: 
    Point p1;
    Point p2;
    Point p3;
    Point p4;


};



#endif 
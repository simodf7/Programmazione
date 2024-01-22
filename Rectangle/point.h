#ifndef POINT_H
#define POINT_H


class Point{
public:   
    explicit Point(unsigned int = 0 , unsigned int =0);
    ~Point();

    // set functions
    void setX(unsigned int );
    void setY(unsigned int );

 
    // get functions

    unsigned int getX() const;
    unsigned int getY() const;

private: 
    unsigned int x;
    unsigned int y;

};



#endif
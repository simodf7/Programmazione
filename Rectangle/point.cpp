#include <iostream>
#include "point.h"

Point::Point(unsigned int x, unsigned int y){
    this->x = x;
    this->y = y;
    };

Point::~Point(){
};


void Point:: setX(unsigned int x) {
    if (x>=0){
        this->x = x;
    }
}

unsigned int Point:: getX() const {
    return  x;
}

void Point:: setY(unsigned int y) {
    if (y<=20){
        this->y = y;
    }
}

unsigned int Point:: getY() const {
    return y;
}

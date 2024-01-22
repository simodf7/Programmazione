//driver.cpp
#include <iostream>
#include "Rectangle.h"
using std::cout;


int main(){
	Point point1{6,10};
	Point point2{18,10};
	Point point3{18,20};
	Point point4{6,20};
	Rectangle rectangle{point1,point2,point3,point4};
	cout<<"Rectangle height: "<<rectangle.rectHeight()<<"\n";
	cout<<"Rectangle width: "<<rectangle.rectWidth()<<"\n";
	cout<<"Rectangle perimeter: "<<rectangle.rectPerimeter()<<"\n";
	cout<<"Rectangle area: "<<rectangle.rectArea()<<"\n";
	rectangle.drawRect();
}
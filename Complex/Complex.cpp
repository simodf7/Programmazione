#include "Complex.h"
#include <iostream>


Complex operator+(const Complex& c1, const Complex& c2){

    Complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;

    return c3;
}

Complex operator-(const Complex& c1, const Complex& c2){

    Complex c3;
    c3.real = c1.real - c2.real;
    c3.imag = c1.imag - c2.imag;

    return c3;
}


Complex operator*(const Complex& c1, const Complex& c2){

    Complex c3;
    c3.real = (c1.real*c2.real)-(c1.imag*c2.imag);
    c3.imag = (c1.real*c2.imag)+(c1.imag*c2.real);

    return c3;
}

Complex operator/(const Complex& c1, Complex& c2){

    Complex c3,c4;
    c4 = c2.coniugate();
    std::cout << "c2 coniugate is " << c4 << "\n";
    c3 = c1 * c4;

    // std::cout << "c1*c2 coniugate is " << c3 << "\n";
    // std::cout << "c1*c2 coniugate is " << c3 << "\n";

    c3.real /= c2.squaredModulus();
    c3.imag /= c2.squaredModulus();

    return c3;
}

std::ostream& operator<<(std::ostream& out, const Complex& c){

    if(c.real == 0){
        out << c.imag << "j";
    }
    else if (c.imag < 0){
        out << c.real << c.imag << "j";
    }
    else out << c.real << "+" << c.imag << "j";

    return out;
}

Complex::Complex(float real, float imag){

    this->real = real;
    this->imag = imag;
}


bool Complex::operator==(const Complex& c){
    return (this->real == c.real && this->imag == imag)? true : false;
}

float Complex::squaredModulus() const{
    return (real * real + imag * imag);
}


Complex Complex::coniugate(){

    Complex c1;
    c1.real = this->real;
    c1.imag = -(this->imag);
    return c1;
}
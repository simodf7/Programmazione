#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{

    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&,Complex&);
    friend std::ostream& operator<<(std::ostream &, const Complex&);

private:

    float real;
    float imag;
    

public:
 
    // explicit Complex(float = 0.0 , float = 0.0); non autorizza la conversione implicita da reale a complesso
    Complex(float = 0.0 , float = 0.0); // autorizza la conversione implicita
    bool operator == (const Complex&); 
    float squaredModulus() const;
    Complex coniugate();

};



#endif
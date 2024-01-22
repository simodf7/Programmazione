// Polynomial.h

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {

  friend bool operator==(const Polynomial &lhs, const Polynomial &rhs);
  friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);
  friend Polynomial operator*(const Polynomial &lhs, double rhs);
  friend Polynomial operator*(double lhs, const Polynomial &rhs);
  friend Polynomial operator*(const Polynomial&, const Polynomial&);
  friend std::ostream &operator<<(std::ostream &out, const Polynomial &rhs);


 private:
  int size;       // grado+1
  double *coefs;  // coefficienti

 public:

  // costruttori
  Polynomial();                                        // default
  Polynomial(const double coefficients[], int size);  // completo
  Polynomial(const Polynomial &rhs);                  // costruttore copia
  explicit Polynomial(double const_term);              // grado 0

  ~Polynomial();  // distruttore

  int degree() const;                               // grado del polinomio
  void print(std::ostream &out = std::cout) const;  // stampa a video

  // operatori di assegnazione
  Polynomial &operator=(const Polynomial &rhs);
  Polynomial operator+=(const Polynomial &rhs);
  Polynomial operator*=(double rhs);

};



#endif
// Polynomial.cpp
#include "Polynomial.h"
// <iostream> è incluso in Polynomial.h

// l'operatore booleano == non può essere all'interno della classe.
// Questo perchè può essere chiamato come Polynomial == Polynomial
// abbiamo definito allora operator== come funzione friend: non è interna alla classe,
// ma può accedere ai dati membro privati.

bool operator==(const Polynomial &lhs, const Polynomial &rhs) {
    if (lhs.size != rhs.size) {
        // se le dimensioni non corrispondono, sicuramente non sono uguali i due polinomi
        return false;
    } else {
        for (int i = 0; i < rhs.size; ++i) {
            if (lhs.coefs[i] != rhs.coefs[i]) {
                // confronto tutti i coefficienti
                return false;
            }
        }
    }
    // se finora non ho trovato differenze, allora i due polinomi coincidono
    return true;
}


Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs){


    // Polynomial newp = p;
    // newp.size = (this->size + p.size)-1;
    // std::cout << "/Debug grado : " << newp.size << "\n";

    // int sum{0};

    // for (int i=0; i<(newp.size); ++i){
    //     std::cout << "/Debug i : " << i << "\n";
    //     for (int j=0; j<=i; ++j){
    //         // std::cout << "/Debug this: " << this->coefs[j] << "\n";
    //         // std::cout << "/Debug p: " << p.coefs[j] << "\n";
    //         std::cout << "/Debug j : " << j << "\n";
    //         sum += (this->coefs[j] * p.coefs[i-j]);
    //         std::cout << "/Debug: " << sum << "\n";
    //     }
    //     newp.coefs[i] = sum;
    // }

    // return newp;




    // int product_size = lhs.degree() + rhs.degree() + 1;
    // double* product{new double[product_size]};


    // for(int i=0; i<product_size; i++){
    //     for(int j=0; j<rhs.size; j++){
    //         for(int k=0; k< lhs.size; k++){
    //             if((k+j)==i)
    //                 product[i] += lhs.coefs[k]*rhs.coefs[j];
    //         }
    //     }
    // }

    // Polynomial result(product,product_size);
    // delete [] product;
    // return result;

  
    int newsize = lhs.degree()+rhs.degree();
    double* vec = new double[newsize+1]{};
    
    for(int i=lhs.size-1;i>=0;i--){
        for(int j=rhs.size-1;j>=0;j--){
            vec[i+j] += lhs.coefs[i]*rhs.coefs[j];
        }
    }

    Polynomial answer(vec,newsize+1); //Invoco il costruttore della classe
    return answer;

    delete[] vec;
        


}







// costruttore di default: p(x)=0
Polynomial::Polynomial() : size{1}, coefs{new double[1]} {
    coefs[0] = 0.0;
}

// costruttore per i polinomi di grado 0: p(x) = cost
Polynomial::Polynomial(double const_term) : size{1}, coefs{new double[1]} {
    coefs[0] = const_term;
}

// costruttore per i polinomi completi
Polynomial::Polynomial(const double coefficients[], int _size) : size{_size}, coefs{new double[_size]} {
    for (int i = 0; i < size; i++) {
        coefs[i] = coefficients[i];
    }
}

// copy constructor
// perchè c'è necessità di implementare un copy constructor?
// tra i dati membro del polinomio, c'è solo un puntatore (ad array). Se banalmente copiassimo
// lhs.coefs = rhs.coefs, l'array sarebbe condiviso, e una modifica ad un polinomio sarebbe applicata anche
// all'altro. Allochiamo quindi un nuovo array e copiamo "a mano" tutti i coefficienti

Polynomial::Polynomial(const Polynomial &rhs) : size{rhs.size}, coefs{new double[rhs.size]} {
    for (int i = 0; i < size; i++) {
        coefs[i] = rhs.coefs[i];
    }
}

// distruttore
// il distruttore deve essere esplicito perchè non possiamo semplicemente "dimenticare" il puntatore
// dei coefficienti, ma dobbiamo anche eliminare l'array vero e proprio.

Polynomial::~Polynomial() {
    delete[] coefs;
}

// grado del polinomio
int Polynomial::degree() const {
    return size - 1;
}

// stampa del polinomio. &out di default è std::cout
void Polynomial::print(std::ostream &out) const {
    if (size == 0) {
        // niente da stampare
        return;
    }

    for (int i = size - 1; i > 0; i--) {
        if (coefs[i]==1){
            out  << "x^" << i << " + ";
        }
        else out << coefs[i] << " x^" << i << " + ";
    }
    out << coefs[0];        // termine noto
}

// fa parte della classe Polynomial
Polynomial Polynomial::operator+=(const Polynomial &rhs) {
    // costruisco un nuovo polinomio
    // la dimensione è quella del polinomio di grado maggiore
    int newSize = (rhs.size > size) ? rhs.size : size;
    // nuovo array dei coefficienti, inizializzato a 0 con la lista {}
    auto *newCoef = new double[newSize]{};
    // aggiungo i coefficienti del primo e del secondo polinomio
    for (int i = 0; i < rhs.size; i++) {
        newCoef[i] += rhs.coefs[i];
    }
    for (int i = 0; i < size; i++) {
        newCoef[i] += coefs[i];
    }
    // pulisco il vecchio array coefs
    delete[] coefs;
    // setto il puntatore coefs all'array nuovo
    coefs = newCoef;
    size = newSize;
    // il tipo dell'operatore è Polynomial, quindi ritorno l'oggetto puntato dal puntatore this
    return *this;
}

// moltiplicazione per una costante
Polynomial Polynomial::operator*=(double rhs) {
    for (int i = 0; i < size; i++) {
        coefs[i] *= rhs;
    }
    return *this;
}

// operatore di assegnazione
Polynomial& Polynomial::operator=(const Polynomial &rhs) {
    if (this == &rhs) {
        return *this;
        // se erano già uguali non c'è bisogno di effettuare l'assegnazione
    } else {
        // cancello il vecchio array
        delete[] coefs;
        // creo il nuovo array e assegno i coefficienti
        coefs = new double[rhs.size];
        size = rhs.size;
        for (int i = 0; i < size; ++i) {
            coefs[i] = rhs.coefs[i];
        }
    }
    return *this;
}

//da qui le funzioni non appartengono più alla classe

// operatore somma
// non appartiene alla classe perchè viene usato come polynomial + polynomial = polynomial
// sfrutta l'operatore += dichiarato prima
Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs) {
    Polynomial tmp{lhs};
    tmp += rhs;
    return tmp;
}

// operatore prodotto - come somma
// dichiarato tre volte per coprire sia i casi polinomio * costante, costante * polinomio e polinomio * polinomio
Polynomial operator*(const Polynomial &lhs, double rhs) {
    Polynomial tmp{lhs};
    tmp *= rhs;
    return tmp;
}

Polynomial operator*(double lhs, const Polynomial &rhs) {
    return rhs * lhs;
}


// operatore di inserimento
std::ostream &operator<<(std::ostream &out, const Polynomial &rhs) {
    rhs.print(out);
    return out;
}
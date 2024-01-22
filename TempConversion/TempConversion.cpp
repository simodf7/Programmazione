#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;


int main(){

    float temp;
    char scala;
    float tF;
    float tC;


    cout << "Inserisci un valore di temperatura: ";
    cin >> temp;
    cout << endl;
    cout << "inserisci scala: ";
    cin >> scala;



    if (scala == 'C'){
        tF = (temp)*(static_cast<float>(9)/5)+32;
        cout << setprecision(3);
        cout << "Temperatura: " << tF; 
    }

    if (scala == 'F'){
        tC= (temp-32)*(static_cast<float>(5)/9);
        
        cout << "Temperatura: " << tC; 
    }

}


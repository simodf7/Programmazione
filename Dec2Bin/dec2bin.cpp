#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main(){
    unsigned int number;
    unsigned int digits[20];
    unsigned int ndigits{0};

    cout << "Enter the number: " << endl;
    cin >> number;

    while(number !=0){
       // cout << "Counter prima:" << ndigits <<endl;
        digits[ndigits++] = number % 2;
        //cout << "Resto: " << number % 2 << endl;
        //cout << "Counter dopo: " << ndigits << endl;
        //cout <<"Numero prima: " << number << endl;
        number /= 2;
        //cout <<"Numero dopo: " << number << endl;
        //cout << "-----" << endl;
    }

    cout << "-----" << endl;

    cout <<"Il numero convertito: ";
    for(int i=ndigits-1; i>=0; i--){
        //cout << "Counter: " << i << endl;
        cout << digits[i]; 
    }


}

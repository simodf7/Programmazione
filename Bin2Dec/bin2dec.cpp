#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pow;

unsigned int conversion(unsigned int );

int main(){
    unsigned int number;

    cout << "Enter the number to convert: " << endl;
    cin >> number;
    cout << "-----" << endl;
    cout << "The converted number is " << conversion(number);
}


unsigned int conversion(unsigned int n){

    vector<unsigned int> v;
    unsigned int c{0};

    while(n !=0){
        v.push_back(n % 10);
        n /= 10;
    }

    for(int i=v.size()-1; i>=0; i--){
        //cout << "Counter: " << i << endl;
        v[i] = v[i]*pow(2,i);
        c += v[i];
    }

    return c;
}
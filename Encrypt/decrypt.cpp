#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void swap (unsigned int []);
void decrypt(unsigned int []);

int main (){
    unsigned int num;
    unsigned int digits[4];
    
    cout << "Enter the number you want to decrypt: " ;
    cin >> num;


    for(int i=3; i>=0; --i){
        digits[i] = num % 10;
        num /=10;
    }

    decrypt(digits);

    cout << "Decrypted number: " ;
    for(int i=3; i>=0; --i){
        cout << digits[i];
    }


}

void decrypt(unsigned int v[]){
    for(int i=3; i>=0; --i){
        if (v[i] >= 7){
            v[i]-=7;
        }
        else v[i]=v[i]+3;
    }

    swap(v);

}


void swap (unsigned int v[]){
    int temp;
    temp = v[3];
    v[3] = v[0];
    v[0] = temp;


    temp = v[2];
    v[2] = v[1];
    v[1] = temp;
}


/*
void deswap (unsigned int v[]){
    int temp;

    temp = v[0];
    v[3] = v[0];
    v[3] = temp;


    temp = v[2];
    v[1] = v[2];
    v[2] = temp;
}
*/

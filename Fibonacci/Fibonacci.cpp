#include <iostream>
#include <iomanip>
using std::endl;
using std::cout;
using std::cin;


int main(){
    int firstNumber{0};
    int secondNumber{1};
    int thirdNumber;
    int num;

    cout <<"Enter the final term of the Fibonacci series you want to show:  "; 
    cin >> num;

    for (int i=0; i<num; i++){
        if (i<=1){
            cout << "F(" << i << ")= " << i << endl;
        }
        else {
            thirdNumber = firstNumber + secondNumber;
            secondNumber = thirdNumber;
            cout << "F(" << i << ")= " << thirdNumber << endl;
            firstNumber = secondNumber;
        }
    }

    

   return 0;
};

#include <iostream>
#include <iomanip>
using std::endl;
using std::cout;
using std::cin;
using std::setw;

int fibonacci(int );

int main(){
    int num;

    cout <<"Enter the final term of the Fibonacci series you want to show:  "; 
    cin >> num;

    cout << "F(" << num << ") = " << fibonacci(num) << endl;
    return 0;
};


int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    else return fibonacci(n-1)+fibonacci(n-2);
}
#include <iostream>
#include <vector>
#include <cstring>
using std::cin; using std::cout ; using std::vector; using std::endl;


int main(){

    std::string* n = new std::string[2];
    std::getline( std::cin, n[1]);
    std::cout << n[1];

    delete[] n;
    
   
}

   

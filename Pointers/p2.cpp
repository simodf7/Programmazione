#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "fon";
    string s2 = "one";

    char* x{&s1[0]};
    char* y{&s2[0]};

    
    for(int i=0; i<s1.size(); i++){
        cout <<  *(x+i); 
    }

    for(int i=0; i<s1.size(); i++){
        *(x+i) = *(y+i); 
    }

    cout << endl;

    for(int i=0; i<s1.size(); i++){
        cout << *(x+i); 
    }

}
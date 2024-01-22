#include <iostream>
#include <array>
#include <string>
using std::array;
using std::string;
using std::cout;

int max(int , int );
void lcsLength(string& , string&, int, int);


int main (){
    string s1 = "stone";
    string s2 = "one";

    //std::cout<<"Length of the Longest common sequence of s1 and s2 is: " << 
    lcsLength(s1,s2, s2.length(), s1.length());

}

void lcsLength(string& x, string& y, int m, int n){

    array<array<int, 10>, 10> v{};

    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if (x[i-1]==y[j-1]){
               v[i][j] = 1 + v[i-1][j-1]; 
            }
            else  v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }

    cout << std::endl;

    for(int i=0; i<n+1; i++){  
        for(int j=0; j<m+1; j++){
            cout << v[i][j] << " ";
        }
        cout << std::endl;
    }
     
    cout << "Length of longest common subsequence is " << v[n][m];

}



int max(int a, int b){
    if(a>b){
        return a;
    }
    else if (a<b){
        return b;
    }
}
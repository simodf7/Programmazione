#include <iostream>
#include <string>


int max(int , int );
int lcsLength(std::string ,std::string, int, int);

int main (){

    std::string s1 = "stone";
    std::string s2 = "one";

    std::cout<<"Length of the Longest common sequence of s1 and s2 is: " << lcsLength(s1, s2, 0,0); 

}

int lcsLength(std::string a, std::string b, int i, int j){
    if (a[i]==0 || b[j]==0)
        return 0;
    else if(a[i]==b[j])
        return 1 + lcsLength(a, b, i+1, j+1);
    else return max(lcsLength(a,b, i+1,j), lcsLength(a,b,i,j+1));
}

/*
std::string lcs(std::string a, std::string b, int i, int j){
    if (a[i]==0 || b[j]==0)
        return " ";
    else if(a[i]==b[j])
        return a[i] + lcs(a, b, i+1, j+1);
    else lcs(max(lcsLength(a,b, i+1,j), lcsLength(a,b,i,j+1)));

}
*/

int max(int a, int b){
    if(a>b){
        return a;
    }
    else if (a<b){
        return b;
    }

}
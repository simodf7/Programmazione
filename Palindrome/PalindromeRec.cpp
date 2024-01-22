#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

bool isPalindromeRec(unsigned int [], int , int );

int main(){

   unsigned int ndigits{0};
   unsigned int digits[20];
   unsigned int number{0};

   cout << "Insert the Number: ";
   cin >> number;

   while(number !=0){
      digits[ndigits] = number % 10;
      number = number/10;
      ndigits = ndigits+1;
   }

   cout <<endl;
   if(isPalindromeRec(digits, 0, ndigits-1)){
      cout << "The number you entered is Palindrome" << endl;
   }
   else{
      cout << "The number you entered is not Palindrome";
   }

   return 0;
};


bool isPalindrome(unsigned int v[], int l){
   bool pal{true};
   int i{0};
   while (i<l/2){
      if(v[i] != v[l-i-1]){
         pal = false;
         break;
      }
      ++i;
   }
   return (pal);
};


bool isPalindromeRec(unsigned int v[], int left, int right){
   if (left < right){
   return (v[left]==v[right] && isPalindromeRec(v, ++left, --right));
   }
   else return true;
};

#include <iostream>
#include <vector>
#include "quick.h"

template <typename T>
int binSearch(std::vector<T> v, int e){
    int left = 0;
    int right = v.size()-1;
    int mid;

    while (left<=right){
        mid = (left+right)/2;
        //std::cout << mid << "\n";
        if (v[mid]==e){
            return mid;
        }
        else if (v[mid]<e)
            left = mid+1; 
        else right = mid-1;
    }

    return -1;
}


template <typename T>
int binSearchRec(std::vector<T> v, int e, int left, int right){
    //quickSort(v, 0, v.size()-1);
    int mid;

    if (left<=right){
        mid = (left+right)/2;
        if (v[mid]==e){
            return mid;
        }
        else if (v[mid]<e)
            return binSearchRec(v,e, mid+1, right);
        else  return binSearchRec(v,e, left, mid-1);
    }
    else return -1;


}

int main(){

    std::vector <int> s = {12,5,89,6,78,90,121};
    //std::cout << s[0] << "\n";
    //int s[] = {12,5,89,6,78,90,121};
    //int dim = sizeof(s)/sizeof(s[0]);
    displayVector(s);
    quickSort(s, 0, s.size()-1);
    displayVector(s);

    int t;
    t = binSearchRec(s,78,0,6);
    if (t== -1){ std::cout <<"Vector doesn't have the element you required";}
    else std::cout << "The element is in position " << t; 
    
    // t = binSearch(s,6);
    // if (t == -1){ std::cout <<"Vector doesn't have the element you required";}
    // else std::cout << "The element is in position " << t; 
    
}


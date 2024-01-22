#include "Heap.h"
#include <iostream>

using std::cout;

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    Heap s(arr,n);
    s.heapsort();
    

}


template<typename T>
void printArray(T* a, int n){
    for(int i=0; i<n; ++i){
        cout << "v[" <<  i << "] = " << a[i] << "\n";
    }
}


#include <iostream>

using std::cin;
using std::cout;

//bool check(int* , int , int );
bool binSearch(int* , int , int);
void swap(int* , int,int );
int partition (int* , int , int );
void quickSort(int* , int , int );
void printArray(int* , int );
bool check(int* ,int , int ); //Il check lo posso fare solo su un vettore ordinato perche la binary search si basa su un vettore ordinato



int main(){

    int c=0;
    int* p;
    int n;
    int d=0;
    p = new int;

    do{
        c++; 
        cin >> n; 

        cout << "/Debug Prima: " << c << "\n" ;

        if (n == '\0'){
            d=1;
        }

        cout << "/Debug d: " << d << "\n" ;

        if(c==1 && d==0){
            cout << "\n\n";
            cout << "/Debug Counter: " << c-1 << "\n"; 
            cout << "/Debug Pointer: " << (p+c-1) << "\n";
            cout << "/Debug Value Before: " << *(p+c-1) << "\n";
            p[0]=n;
            cout << "/Debug Value After: " << *(p+c-1) << "\n";
        }
        else if (d==0){
            if (!binSearch(p,n,c)){
                    cout << "/Debug: True" << "\n"; 
                    cout << "/Debug Counter: " << c-1 << "\n"; 
                    cout << "/Debug Pointer: " << (p+c-1) << "\n";
                    cout << "/Debug Value Before: " << *(p+c-1) << "\n"; 
                    p[c-1] = n;
                    cout << "/Debug Value After: " << *(p+c-1) << "\n";
                }
                else{
                    c--;
                    cout << "/Debug: False" << "\n"; 
                }
        }
        else c--;
        
 
        cout << "/Debug Dopo: " << c << "\n" ;
        cout << "\n";

    }while(n != '\0');


    printArray(p,c);
    
    delete [] p;
 
}


bool binSearch(int* s, int e, int m){

    quickSort(s, 0, m-1);

    int left = 0;
    int right = m-1;
    int mid;

    while (left<=right){
        mid = (left+right)/2;
        if (s[mid]==e){
            return true;
        }
        else if (s[mid]<e)
            left = mid+1; 
        else right = mid-1;
    }

    return false;
}


/*
void displayVector(int* v, int m){
    for (int i=0; i<m; ++i)
        cout << "v[" << i << "] = " << v[i] <<"\n";
}
*/

void quickSort(int* A,int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

int partition(int*A ,int p,int r){
    int x=A[p];
    int i=p-1;
    int j=r+1; 
    while(true){
        do
        {
            j=j-1;
        } while (A[j]>x);
        do
        {
            i=i+1;
        } while (A[i]<x);
        if(i<j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}

void swap(int* A,int i,int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

bool check(int* A,int num, int c){ //Il check lo posso fare solo su un vettore ordinato perche la binary search si basa su un vettore ordinato
    int p=0;
    int r=c-1;
    quickSort(A,p,r);
    while(p<=r){
        int mid=(p+r)/2;
        if(A[mid]==num){
            return true;
        }
        else if(num>A[mid]){
            p=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return false;
}
 
/* Function to print an array */
void printArray(int* arr, int size)
{
    cout << "Pointer is : " << arr << std::endl;
    for (int i = 0; i < size; i++)
        cout << *(arr+i) << " ";
    cout << std::endl;
}
 

/*
        if(c == 1){
            continue;
        }
        else {
            if(binSearch(p,n,c)){
              p[c-1] = n;
            }
            else c--;
        }




bool check(int* v, int c, int n){
    for(int i=0; i<c-1; i++){
        if(v[i]==n){
            return true;
        }
    }
}

*/
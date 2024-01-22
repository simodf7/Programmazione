#include <iostream>   //sbagliato
#include <string>
using std::cout; 
using std::cin;

void displayArray(int* , int );
int sumArray(int* , int );
void insertArray(int* , int );

int main(){
   
    int n; 
    cout << "Di quanti numeri vuoi fare la somma?\n";
    cin >> n;

    int* p = new int[n];

    cout << "Inserisci i numeri di cui vuoi fare la somma: \n"; 
    insertArray(p,n);
    displayArray(p,n);
    cout << "\nLa somma dei numeri: " << sumArray(p,n) ; 

}

void insertArray(int* v, int cont){
    int num;
    for (int i=0; i<cont; i++){
        cin >> num;
        *(v+i) = num;
    }
}


void displayArray(int* v, int cont){
    for(int i=0; i < cont; i++){
        cout << *(v+i) << " " ;
    }
}


int sumArray(int* v, int cont){
    int sum=0;
    for(int i=0; i < cont; i++){
        sum += *(v+i);
    }
    return sum;
}
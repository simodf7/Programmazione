// Insertion Sort O(n^2)
#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>& );

template <typename T>
void insertVector(std::vector<T>& );

template <typename T>
void printVector(std::vector<T>& );




int main(){

    std::vector<int> v;
    insertVector(v);
    std::cout << "Original Vector\n";
    printVector(v);
    std::cout << "\n";
    insertionSort(v);
    std::cout << "Ordinated Vector\n";
    printVector(v);





};


template <typename T>
void insertionSort(std::vector<T>& v){

    for(int j=1;j<v.size();j++)
        {
            T key=v[j]; //Salvo il valore del numero in posizione j nel vettore
            int i=j; //Salvo la posizione valutata

            while(i>0 && v[i-1]>key) //Se il valore in pos precedente è maggiore
                {                       //salvo tale valore in posizione i=j e decremento i
                    v[i]=v[i-1];    //itero il procedimento finchè andando indietro non trovo un valore
                    i--;                //minore di key, quindi esco dal while e salvo key nella posizione i raggiunta
                }
            v[i]=key; //Salvo in posizione i che sarebbe j-1 il valore iniziale e ripeto il ciclo da capo
        }

}



template <typename T>
void insertVector(std::vector<T>& v){
    int size{0};
    T elem;
    std::cout << "How long is your vector: "; std::cin >> size;

    for(int i=0; i<size; i++){
        std::cin >> elem;
        v.push_back(elem);
    } 
}


template <typename T>
void printVector(std::vector<T>& v){
    
    for(int i=0; i<v.size(); i++){
        std::cout << "v[" << i << "] = " << v[i] << "\n";
    } 
}
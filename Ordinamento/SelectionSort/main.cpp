// Bubble sort O(n^2)
#include <iostream> 
#include <vector>

template<typename T>
void swap(std::vector<T>&, int  , int );

template <typename T>
void selectionSort(std::vector<T>& );

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
    selectionSort(v);
    std::cout << "Ordinated Vector\n";
    printVector(v);





};

template<typename T>
void swap(std::vector<T>& v, int i , int j){
    T temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    
}

template <typename T>
void selectionSort(std::vector<T>& v){



    for(int i=0; i<v.size(); i++){
        int min{i};
        for(int j=i+1; j<v.size(); j++){
            if(v[j] < v[min]){ min = j;}
        }
        swap(v, min, i);
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
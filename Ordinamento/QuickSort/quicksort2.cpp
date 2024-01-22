// Quick Sort O(n^2)
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
void displayVector(vector<T>& );
template <typename T>
void swap(vector<T>& , int , int );

template <typename T>
int partition(vector<T>& , int , int );
template <typename T>
void quickSort(vector<T>& ,int , int );


int main()
{
    vector <int> s{7,87,54,19,3};
    /*
    int num;

    cout << "Enter the number of elements: " << endl;
    cin >>num;

    int value;
    cout << "Enter the elements: " << endl;
    for (int i=0; i<=num-1; i++){
        cin >> value;
        s.push_back(value); 
    }

    cout << "Vector is: " << endl;
    displayVector(s);
    */
    cout << "---------" << endl;
    quickSort(s, 0, s.size()-1);


    cout << "Ordinated vector is: " << endl;

    displayVector(s);

    return 0;
}

template <typename T>
void displayVector(vector<T>& v){
    for (int i=0; i<= v.size()-1; i++)
        cout << "v[" << i << "] = " << v[i] << endl;
};

template <typename T>
void swap(vector <T>& v, int a, int b){ // error = a function definition is not allowed here before '{' token
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}



template <typename T>
int partition(vector<T>& v, int l, int r){

    int p = l; //pivot
    int i = l-1;
    int j = r+1;

    while (true){
        do{
            j-=1;
        }while(v[j] > v[p]);

        do{
            i+=1;
        }while (v[i] < v[p]);

        if(i<j)
            swap(v,i,j);
        else return j;
    }

}


template <typename T>
void quickSort(vector <T>& v, int l, int r) {
 // i commenti vanno aggiornati
    int p = partition (v,l,r);
    cout << "Partition: " << p << endl;

    if (l<r){
        quickSort(v, l, p);
        quickSort(v, p+1, r);
    }
}
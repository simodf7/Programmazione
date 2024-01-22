#include <vector>
using std::vector;



template <typename T>
void swap(vector <T>& v, int a, int b){ 
    T temp = v[a];
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
            j--;
        }while(v[j] > v[p]);

        do{
            i++;
        }while (v[i] < v[p]);

        if(i<j)
            swap(v,i,j);
        else return j;
    }

}

template <typename T>
void quickSort(vector <T>& v, int l, int r) {
 // i commenti vanno aggiornati
    //std::cout << "Partition: " << p << endl;

    if (l<r){
        int p = partition (v,l,r);
        quickSort(v, l, p);
        quickSort(v, p+1, r);
    }
}


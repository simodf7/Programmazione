#include <iostream>
#include <vector>

/*
void displayVector(std::vector<int>& );
void swap(std::vector<int>& , int , int );
int partition(std::vector<int>& , int , int );
void quickSort(std::vector<int>& ,int , int );

int main()
{
    std::vector <int> s = {12,5,89,6};
    int num;

    std::cout << "Enter the number of elements: " << std::endl;
    cin >>num;

    int value;
    std::cout << "Enter the elements: " << std::endl;
    for (int i=0; i<=num-1; i++){
        cin >> value;
        s.push_back(value); 
    }

    std::cout << "Vector is: " << std::endl;
    displayVector(s);
    
    std::cout << "---------" << std::endl;
    quickSort(s, 0, 3);


    std::cout << "Ordinated vector is: " << std::endl;

    displayVector(s);

    return 0;
}
*/

void displayVector(std::vector<int>& v){
    for (int i=0; i<= v.size()-1; i++)
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
};


void swap(std::vector <int>& v, int a, int b){ 
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}




int partition(std::vector<int>& v, int l, int r){

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


void quickSort(std::vector <int>& v, int l, int r) {
 // i commenti vanno aggiornati
    int p = partition (v,l,r);
    //std::cout << "Partition: " << p << std::endl;

    if (l<r){
        quickSort(v, l, p);
        quickSort(v, p+1, r);
    }
}
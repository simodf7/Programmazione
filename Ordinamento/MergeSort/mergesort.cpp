// Merge Sort O(nlog(n))
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
void merge(vector<T>&  , int , int , int );
template<typename T>
void mergeSort(vector<T>& ,int , int );

int main(){

    vector <int> s;
    int num;
    cout << "Enter the number of elements to be sorted: " ;
    cin >> num;

    int value;
    cout << "Enter the elements: " << endl;
    for (int i=0; i<=num-1; i++){
        cin >> value;
        s.push_back(value); 
    }

    cout << "Vector is: " << endl;
    for (int i=0; i<= num-1; i++){
        cout << "s[" << i << "] = " << s[i] << endl;
    }

    cout << "---------" << endl;
    mergeSort(s,0,num-1);


    cout << "Ordinated vector is: " << endl;
    for (int i=0; i<= num-1; i++){
        cout << "s[" << i << "] = " << s[i] << endl;
    }



}


template <typename T>
void mergeSort(vector<T>& v,int l, int r){
  /** 
* @brief splitta il vettore a in due pezzi e chiama se stessa sulle due metà
* @param a il vettore su cui lavorare
* @param p il punto iniziale del vettore su cui lavorare
* @param r il punto finale del vettore su cui lavorare
*/
    
    int m;
    if (l<r){
        m=(l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v,m+1,r);
        merge(v,l,r,m);
    }
}


template <typename T>
void merge(vector<T>& v , int l, int r, int m){
 
 /** 
* @brief fonde due sequenze ordinate in un'unica sequenza ordinata
* 
* @param a il vettore contenente le due sequenze
* @param p punto iniziale
* @param r punto di termine
* @param q punto di separazione tra le due sequenze
*/
    int i,j,k;
    static vector<T> c(v.size());  // c è dichiarato come static per non doverlo inizializzare ogni volta - pensa
                                     // se a avesse dimensione 1000!
    i = l;
    j = m+1;
    k = l;

    while (i <= m && j <= r){
    // questo primo ciclo confronta elemento per elemento le due sequenze, prendendo
    // di volta in volta l'elemento maggiore e copiandolo in c
        if (v[i] < v[j]){
            c[k] = v[i];
            k++;
            i++;
        }
        else {
            c[k] = v[j];
            k++;
            j++;
        }
    }
    // Prima o poi una delle due liste finisce, quindi facciamo due while, uno che viene eseguito se
    // la prima lista e finita , il secondo se l'altra e finita

    // INfatti quando il primo ciclo avrà finito, una delle due sequenze avrà valori avanzati. 
    // questi due cicli while completano la copia dalle sequenze in c

    while( i<=m ){
        c[k] = v[i];
        k++;
        i++;
    }
 
    while( j <= r ){
        c[k] = v[j];
        k++;
        j++;
    }

    //infine copiamo gli elementi di c in v

    // Infatti ora che c è effettivamente l'unione ordinata delle due sequenze, viene
    // ricopiato in a - elemento per elemento

    for (i=l; i< k ; i++){
        v[i] = c[i];
    } 



}
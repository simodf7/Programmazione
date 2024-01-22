// Prodotto Righe per Colonne
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void insert_Matrix(int** &, int &, int &);
void displayMatrix(int** &, int , int );
void allocateMatrix(int** &, int &, int &);
void matProd(int** , int** , int ** &,int, int, int, int);
void deAllocateMat(int** , int );

int main(){

	int** m1;
	int** m2;
	int** m3;
	int r1,r2,c1,c2;

	cout << "Inserisci la dimensione delle righe della matrice 1: ";
	cin >> r1;
	
	cout << "Inserisci la dimensione delle colonne della matrice 1: ";
	cin >> c1;
	
	cout << "Inserisci la dimensione delle righe della matrice 2: ";
	cin >> r2;
	
	cout << "Inserisci la dimensione delle colonne della matrice 2: ";
	cin >> c2;
	
	
	allocateMatrix(m1,r1,c1);
	allocateMatrix(m2,r2,c2);
	insert_Matrix(m1, r1, c1);
	insert_Matrix(m2, r2, c2);
	matProd(m1,m2,m3,c1,c2,r1,r2);
	cout << endl;
	displayMatrix(m3,r1,c2);
	deAllocateMat(m1,r1);
	deAllocateMat(m2,r2);
	deAllocateMat(m3,c1);

}


void allocateMatrix(int** &mat, int &r, int &c){

	mat = new int*[r];
	for (int i=0; i<r; i++)
	   for (int j=0; j<c; j++)
	      mat[i] = new int[c];


}

void insert_Matrix(int** &mat, int &r, int &c)
{
	for (int i=0; i<r; i++)
	   for (int j=0; j<c; j++)
	      cin >> mat[i][j];

	displayMatrix(mat,r,c);
	 
}

void displayMatrix(int** &mat, int r, int c){
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
	      cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


void matProd(int** m1, int** m2, int ** &m3, int c1, int c2, int r1, int r2){

	if (c1 == r2){
		
		allocateMatrix(m3,c1,r2);
		int sum{0};
		for(int j=0; j<r2; ++j)
			for(int t=0; t<c2; ++t){
				for(int i=0; i<c1; ++i){
					sum += (m1[j][i] * m2[i][t]);
				}
				m3[j][t] = sum;
				sum=0;
			}
    }
    else cout << "It's not possibile to do the matrix product";

}


void deAllocateMat(int** m, int r){
	for (int i = 0; i < r; ++i)
    	delete [] m[i];
	delete [] m;
}
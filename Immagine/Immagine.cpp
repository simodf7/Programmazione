#include "Immagine.h"
#include <sstream>
#include <iostream>


Immagine Immagine::insFilter(){

    Immagine m(row, col);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            m.mat[i][j] = filter(i,j);
        }
    }

    return m;
    
};



Immagine::Immagine(int r,int c): row{r}, col{c}{


    mat = new float*[row];

    for(int i=0; i<row; i++){
        mat[i] = new float[col];
    }


    
}




Immagine::~Immagine(){

    for(int i=0; i<row; i++){
        delete[] mat[i];
    }

    delete[] mat;


}

Immagine::Immagine(const Immagine& l){

    row = l.row;
    col = l.col;

    mat = new float*[row];

    for(int i=0; i<row; i++){
        mat[i] = new float[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            mat[i][j] = l.mat[i][j];
        }
    }
    
    
}

Immagine& Immagine::operator=(const Immagine& l){

    if(this == &l) return *this;

    if(row == l.row && col == l.col){}
    else{
        for(int i=0; i<row; i++){
            delete[] mat[i];
        }

        delete[] mat;

        row = l.row;
        col = l.col;

        mat = new float*[row];

        for(int i=0; i<row; i++){
            mat[i] = new float[col];
        }

    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            mat[i][j] = l.mat[i][j];
        }
    }



    
}


void Immagine::printMat() {

    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
    
}

void Immagine::riempMat(){
    float n;

    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            std::cin >> n;
            mat[i][j] = n;
        }
    }
    
}

float Immagine::filter(int x ,int y){

    int sum{0};
    int c{0};
    for(int i = x-1; i<= x+1; i++){
        //std::cout << "/Debug Iterator i: " << i << "\n";
        for(int j= y-1; j <= y+1; j++){
            if( i>=0 && i<row && j>=0 && j<col){
                //std::cout << "/Debug Iterator j: " << j << "\n";
                c++;
                // std::cout << "/Debug Iterator c: " << c << "\n";
                // std::cout << "/Debug Value: " << mat[i][j] << "\n";
                sum += mat[i][j];
                // std::cout << "/Debug Sum: " << sum << "\n";
                // std::cout << "-------------------- \n"; 
                
            }
            //std::cout << "\n\n"; 
        }
    }

    float mean = (static_cast<float>(sum)/c);
    //std::cout << "/Debug Mean: " << mean << "\n";

    return mean;
    
}

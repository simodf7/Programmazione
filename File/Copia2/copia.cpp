//copia file con argomenti del main

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;
using std::ios;

int main(int argc,char* argv[]){

    if(argc!=3){
        cerr<<"Il numero di argomenti deve essere 3 e nel seguente ordine: "<<endl;
        cerr<<"nome_driver testo.txt testo_copia.txt";
        exit(EXIT_FAILURE);
    }

    int length = 0;
    char* buffer = nullptr;

    ifstream inFile;
    inFile.open(argv[1],ios::in);

    if(!inFile){

        cerr<<"Il file "<<argv[1]<<" non può essere aperto"<<endl;
        exit(EXIT_FAILURE);
        
    }

    inFile.seekg(0,ios::end);
    length = inFile.tellg();
    inFile.seekg(0,ios::beg);
    buffer = new char[length];
    inFile.read(buffer,length);

    ofstream outFile;
    outFile.open(argv[2],ios::out);

    if(!outFile){
        cerr<<"Il file " << argv[2] << " non può essere aperto" << endl;
        delete [] buffer;
        exit(EXIT_FAILURE);
    }

    outFile.write(buffer,length);
    delete [] buffer;

    inFile.close();
    outFile.close();
}
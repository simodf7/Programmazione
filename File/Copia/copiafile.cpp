#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::cerr;
using std::endl;

int main(){
    int lenght=0;
    char* buffer = nullptr; //definisco un puntatore a caratteri e lo inizializzo con il puntatore nullo

    ifstream inFile;
    inFile.open("file.txt",ios::in); //quando apro il file in lettura, il puntatore get si trova all'inizio

    if(!inFile){
        cerr<<"Non è stato possibile accedere al file file.txt"<<endl;
        exit(EXIT_FAILURE);
    }

    inFile.seekg(0,ios::end); //sposto il puntatore get alla fine del file
    lenght = inFile.tellg(); //inFile.tellg() mi da la lunghezza in byte del file
    inFile.seekg(0,ios::beg); //sposto il puntatore get nuovamente all'inizio del file
    buffer = new char[lenght]; //alloco lo spazio in memoria per contenere il contenuto del file
    inFile.read(buffer,lenght); //leggo tutto il file 
    //il file viene visto dal compilatore c++ come una sequenza di byte e quindi come una sequenza di char(ogni char è un byte)

    ofstream outFile;
    outFile.open("copy_file.txt",ios::out); //creo un file per copiare il contenuto di testo.txt

    if(!outFile){

        cerr<<"Non è stato possibile accedere al file copy_file.txt"<<endl;
        delete [] buffer; //prima di uscire dal programma devo deallocare lo spazio in memoria
        exit(EXIT_FAILURE);
        
    }
    outFile.write(buffer,lenght);
    delete [] buffer;

    inFile.close();
    outFile.close();


}
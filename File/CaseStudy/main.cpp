/*Scrivere un programma che consenta ad un gestore del credito di visualizzare
le informazioni sull'account per quei clienti con:
- zero credito (cioè clienti che non devono nulla alla società)
- credito negativo (cioè clienti a cui l'azienda deve denaro) 
- credito positivo (vale a dire, i clienti che devono denaro all'azienda)
• Il programma visualizza un menu e consente al gestore del credito
di scegliere una delle tre opzioni per ottenere informazioni sul credito.
L'opzione 1 produce un elenco di conti con credito zero.
L'opzione 2 produce un elenco di conti con credito negativo.
L'opzione 3 produce un elenco di conti con credito positivo.
L'opzione 4 termina l'esecuzione del programma.
L'inserimento di un'invalida opzione richiede una nuova scelta.*/

#include <iostream>
#include <fstream>
#include <string>

using std::cout; using std::cin;
using std::ifstream; using std::ios;
using std::cerr;
using std::string;

int menu();
void printLine(int, string&, float);
void zeroCredit(ifstream&, int, string&, float);
void negativeCredit(ifstream&, int, string&, float);
void positiveCredit(ifstream&, int, string&, float);



int main(int argc, char** argv){

    int account;
    string name;
    float balance;

    ifstream inFile{argv[1], ios::in};

    if (!inFile){
        cerr << "File could not be opened "; 
        exit(EXIT_FAILURE);
    }


    cout << " - Benvenuto nel Programma di Stampa Conti - \n";
    int request = menu();

    while(request != 4){

        switch (request)
        {
        case 1: 
            zeroCredit(inFile, account, name, balance);
            break;
        case 2:
            negativeCredit(inFile, account, name, balance);
            break;
        case 3:
            positiveCredit(inFile, account, name, balance);
            break;
        case 4:
            break;
        }

        cout << "\n";
        request = menu();
    }

    
    inFile.close();

    cout << "---Programma Terminato";
    return 0;

}


void zeroCredit(ifstream& f, int a, string& n, float b){


    while(!f.eof()){
        f >> a >> n >> b; 
        if(b==0){
            printLine(a,n,b);
        }
    }

    f.clear();
    f.seekg(0);
    

}


void negativeCredit(ifstream& f, int a, string& n, float b){


   while(!f.eof()){
        f >> a >> n >> b; 
        if(b<0){
            printLine(a,n,b);
        }
    }

    f.clear();
    f.seekg(0);
    

}

void positiveCredit(ifstream& f, int a, string& n, float b){

    while(!f.eof()){
        f >> a >> n >> b; 
        if(b>0){
            printLine(a,n,b);
        }
    }

    f.clear();
    f.seekg(0);
    

}



void printLine(int a, string& n, float b){
    cout << a << " - " << n << ", Credit: $" << b << "\n"; 
}


int menu (){

    int n;
    cout << " 1 - Stampa i Conti con credito zero \n";
    cout << " 2 - Stampa i Conti con credito negativo \n";
    cout << " 3 - Stampa i Conti con credito positivo \n";
    cout << " 4 - Esci dal programma \n";

    cout << "Inserisci: "; cin >> n;
    return n;
}
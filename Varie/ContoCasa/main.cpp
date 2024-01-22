#include "Conto.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::cout; using std::cin;
using std::cerr;
using std::ios; using std::ofstream;
using std::string;



//void display(ofstream&, const ClientData&);
int menu ();
void setInitialBalance(Conto&);
void deposit(ofstream&, Conto&);
void withdraw(ofstream&, Conto&);



int main(int argc, char** argv){

    Conto c;
    string filename = argv[1];
    cout << "FILE = " << filename << "\n"; 
    ofstream file;
    file.open(filename, ios::app);

    if (!file){
        cerr << "Balance file could not be opened "; 
        exit(EXIT_FAILURE);
    }

    cout << " - Welcome to Balance program - \n";
    int request;

    while((request = menu()) != 3){

        switch (request)
        {
        case 0:
            setInitialBalance(c);
            break;
        case 1: 
            deposit(file, c);
            break;

        case 2:
            withdraw(file,c);
            break;
        case 3:
            break;
        default:
            cerr<<"\n Errore: Scelta non discponibile";
            break;
        
        }


    }

    file.close();
}



int menu (){

    int n;
    cout << " 0 - Set Initial Balance \n";  // only for the first time
    cout << " 1 - Deposit \n";
    cout << " 2 - Withdraw \n";
    cout << " 3 - Exit program \n";

    cout << "Insert your choice: "; cin >> n;
    return n;
}



void setInitialBalance(Conto& c){
    
    int b; 
    cout << "Insert the initial Balance: "; cin >> b;
    c.setBalance(b);
    
}

void deposit(ofstream& f, Conto& c){

    
    float b; 
    cout << "Insert the amount you want to deposit: " ; cin >> b;

    c.deposit(b);

    int d;
    int m;
    int y;

    cout << "Enter the date of the transaction \n" ; 
    cout << "Day "; cin >> d; cout << "\n";
    cout << "Month "; cin >> m; cout << "\n";
    cout << "Year "; cin >> y; cout << "\n";

    Date dat(d,m,y);
    string s = ((c.toStringDeposit(b))+ "Transaction Date: " + dat.toString());
    string s2 = c.toString();
    f << s;
    f << "\n";
    f << s2;
    f << "\n";
    

    

}




void withdraw(ofstream& f, Conto& c){

    
    float b; 
    cout << "Insert the amount you want to withdraw: " ; cin >> b;

    c.withdraw(b);

    int d;
    int m;
    int y;

    cout << "Enter the date of the transaction \n" ; 
    cout << "Day "; cin >> d; cout << "\n";
    cout << "Month "; cin >> m; cout << "\n";
    cout << "Year "; cin >> y; cout << "\n";

    Date dat(d,m,y);
    string s = ((c.toStringWithdraw(b))+ "Transaction Date: " + dat.toString());
    string s2 = c.toString();
    f << s;
    f << "\n";
    f << s2;
    f << "\n";

}





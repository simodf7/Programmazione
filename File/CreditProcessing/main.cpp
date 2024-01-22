/* Using random-access file-processing techniques, create a
credit-processing program capable of storing at most 100
fixed-length records for a company that can have up to 100
customers. Each record should consist of an account number
that acts as the record key, a last name, a first name and
a balance. The program should be able to update an account,
insert a new account, delete an account and insert all the
account records into a formatted text file for printing. */


#include "ClientData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::cout; using std::cin;
using std::cerr;
using std::ios; using std::fstream; using std::ofstream;
using std::string;
using std::left; using std::right;
using std::setw; 


//void display(ofstream&, const ClientData&);
int menu ();
void newA(fstream&);
void deleteA(fstream&);
void insert(fstream&);
void update(fstream&);


int main(){

    fstream CreditFile{"Credit.dat", ios::in | ios::binary | ios::out};

    
    if (!CreditFile){
        cerr << "CreditFile could not be opened "; 
        exit(EXIT_FAILURE);
    }
    
    
    ClientData blankClient;

    for(int i=0; i<100; i++){
        CreditFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
    }
    


    cout << " - Welcome to Credit Processing program - \n";
    int request;

    while((request = menu()) != 5){

        switch (request)
        {
        case 1: 
            newA(CreditFile);
            break;

        case 2:
            deleteA(CreditFile);
            break;
        case 3:
            insert(CreditFile);
            break;

        case 4:
            update(CreditFile);
            break;
        default:
            cerr<<"\n Errore: Scelta non discponibile";
            break;
        
        }

    }

    
    CreditFile.close();

    cout << "--- Program terminated";
    return 0;

}



int menu (){

    int n;
    cout << " 1 - New Account \n";
    cout << " 2 - Delete an Account \n";
    cout << " 3 - Insert all the record in a text file \n";
    cout << " 4 - Update an Account \n";
    cout << " 5 - Exit program \n";

    cout << "Insert your choice: "; cin >> n;
    return n;
}



void newA(fstream& f){

    int a;
    string n;
    string l; 
    double b;
 
    cout << "- Insert the number of the Account you wish to insert: "; 
    do{
        cin >> a;
        if (a<=1 && a>=100)
            cout << "Account number must be between 1 and 100 \n";
    }while (a<=1 && a>=100);

    //Seleziono l'account da leggere posizionando correttamente il cursore nel file
    f.seekg((a-1)*sizeof(ClientData));

    //Read record from file
    ClientData client;
    f.read(reinterpret_cast<char*>(&client),sizeof(ClientData));


    //Create record if it doesn't previously exist
    if(client.getAccountNumber()==0){
        cout << "- Insert the First Name: "; cin >> n;
        cout << "- Insert the Last Name: "; cin >> l;
        cout << "- Insert the Balance: "; cin >> b;

        ClientData client(a, n, l, b);

        f.seekp((a-1)* sizeof(ClientData));
        f.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

    }
    else std::cerr<<"Account #"<< a << " already contains information.\n";



}



void deleteA(fstream& f){

    int a;

    cout << "- Insert the number of the Account you wish to delete: "; 
    do{
        cin >> a;
        if (a<1 && a>=100)
            cout << "Account number must be between 1 and 100 \n";
    }while (a<1 && a>=100);


    ClientData client;
    

    f.seekg((a-1) * sizeof(ClientData));
    f.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));



}


void insert(fstream& f){


    ofstream CreditText("test.txt");
    
    if (!CreditText){
        cerr << "File could not be created \n";
        exit(EXIT_FAILURE); 
    }


    f.seekg(0);
    ClientData client;
    f.read(reinterpret_cast<char*> (&client), sizeof(ClientData)); // read first record

    while(!f.eof()){
        if(client.getAccountNumber() != 0){  // non vengono inseriti i record nulli
            CreditText << client.getAccountNumber() << "  " << client.getFirstName() << " "
            << client.getLastName() << " "<< client.getBalance() << "\n";
        }
        f.read(reinterpret_cast<char*>(&client), sizeof(ClientData)); // read next record
    }


    CreditText.close();

}




void update(fstream& f){

        int a;

         cout << "- Insert the number of the Account you wish to insert: "; 
        do{
            cin >> a;
            if (a<=1 && a>=100)
                cout << "Account number must be between 1 and 100 \n";
        }while (a<=1 && a>=100);

        //Devo considerare accountNumber-1 perchè se ad esempio voglio selezionare l'account 3
        //devo saltare di 2 posizioni. Se saltassi di 3 starei selezionando il numero 4
        f.seekg((a-1)*sizeof(ClientData));

        ClientData client;
        //Leggo l'account selezionato
        f.read(reinterpret_cast<char*>(&client),sizeof(ClientData));

        if(client.getAccountNumber()!=0)
        {
            cout<<"\nEnter charge (+) or payment (-):";
            double transaction;
            cin >> transaction;

            //Update record balance
            double oldBalance = client.getBalance();
            client.setBalance(oldBalance+transaction);


            //Move file-position pointer to correct record in file
            f.seekp((a-1)*sizeof(ClientData));

            //Write the updated record over old record in file
            f.write(reinterpret_cast<const char*>(&client),sizeof(ClientData));
        }
        else std::cerr<<"\nAccount #"<< a <<" has no information.\n";    


}






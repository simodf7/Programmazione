#include <iostream>
#include <string>
#include "Warehouse.h"
#include <fstream>
using namespace std;

enum class Choice{NEW=1,DELETE,UPDATE,PRINT,END};

Choice enterChoice();

void newRecord(fstream&);
void deleteRecord(fstream&);
void updateRecord(fstream&);
void createFile(fstream&);
int InsCode();





int main(int argc, char const *argv[])
{
    fstream inoutWhare("wharehouse.dat", ios::in | ios::binary| ios::out);

    if (!inoutWhare) {
        cerr << "Cannot open file. Terminating..." << endl;
        exit(EXIT_FAILURE);
    }

    // devo creare una funzione che contrlla se un file esiste 
    // se non esiste devo istanziarlo con questo for
    // altrimenti me lo sovrascrive ogni cazzo di volta

/*
    Warehouse warehouse;
    for (int i = 0; i < 100; ++i) {
        inoutWhare.write(reinterpret_cast<const char*>(&warehouse), sizeof(Warehouse));
    }
*/

    Choice choice;


    while ((choice=enterChoice())!= Choice::END)
    {
        switch (choice)
        {
        case Choice:: NEW:
            newRecord(inoutWhare);
            break;
        case Choice::DELETE:
            deleteRecord(inoutWhare);
            break;
        case Choice::UPDATE:
            updateRecord(inoutWhare);
            break;
        case Choice::PRINT:
            createFile(inoutWhare);
            break;
    
        }
    
    
    
    } 
    inoutWhare.close();
}


Choice enterChoice() {
    cout<< "\n 1 N, 2 D, 3 U , 4 P, 5 Esc : ";
    int number;
    cin>> number ;

    switch (number)
    {
    case 1:
        return Choice::NEW;
        break;
    case 2:
        return Choice::DELETE;
        break;
    case 3:
        return Choice::UPDATE;
        break;
    case 4:
        return Choice::PRINT;
        break;
    case 5 :
        return Choice::END;
        break;

    
    default:
        cerr<< " \n Errore : scleta non valida";
        break;
    }


    
    

}





void newRecord(fstream& file){

    int code{InsCode()};

    Warehouse warehouse;
    file.seekg(0);

    file.seekg((code-1)*sizeof(Warehouse));

    file.read(reinterpret_cast<char*>(&warehouse),sizeof(Warehouse));

    if(warehouse.getcode()==0){

        string name;
        int qty;
        double price;

        cout<<"\n Inserisci nome, quantita e prezzo :";
        cin>>name>>qty>>price;
        warehouse.setCode(code);
        warehouse.setName(name);
        warehouse.setQuantity(qty);
        warehouse.setPrince(price);
        
        file.seekg((code-1)*sizeof(Warehouse));
        file.write(reinterpret_cast<char*>(&warehouse),sizeof(Warehouse));



    }else
        cerr<< " \n oggetto gia esistente :";


    file.seekg(0);

}



void deleteRecord(fstream& file){


    int code{InsCode()};

    Warehouse warehouse;

    file.seekg((code-1)*sizeof(Warehouse));
    
    file.read(reinterpret_cast<char*>(&warehouse),sizeof(Warehouse));

    if(warehouse.getcode()!=0){
        Warehouse delwarehouse; //vuoto 

        file.seekg((code-1)*sizeof(Warehouse));
    
        file.write(reinterpret_cast<char*>(&delwarehouse),sizeof(Warehouse));

        cout<<" \n  oggetto  deleted : "<< code ;

    }else
        cerr<<" \n Errore oggetto  non esistente ";

    file.seekg(0);

}


void updateRecord(fstream& file){

    int code{InsCode()};



    Warehouse warehouse;
    file.seekg((code-1)*sizeof(warehouse));
    file.read(reinterpret_cast<char*>(&warehouse),sizeof(Warehouse));

    if(warehouse.getcode()!=0){
        string name;
        int qty;
        double price;

        cout<<"\n Inserisci nome, quantita e prezzo :";
        cin>>name>>qty>>price;
        warehouse.setCode(code);
        warehouse.setName(name);
        warehouse.setQuantity(qty);
        warehouse.setPrince(price);

        file.seekg((code-1)*sizeof(warehouse));
        file.write(reinterpret_cast<char*>(&warehouse),sizeof(Warehouse));

        cout<<"\n Oggetto  "<< code <<"Aggiornato ";
        


    }else{

        cerr<<"\n oggetto non esistente ";
    }


    file.seekg(0);

}



void createFile(fstream& file){

    ofstream print{"print.txt"};

    if (!print) {
        cerr << "Cannot open file. Terminating..." << endl;
        exit(EXIT_FAILURE);
    }

    Warehouse warehouse;

    file.seekg(0);
    file.read(reinterpret_cast<char*>(&warehouse),sizeof(Warehouse));

    while (!file.eof())
    {   
        
        if(warehouse.getcode()!=0){

            print<<warehouse.getcode()<<" " <<warehouse.getName()<<" "<< warehouse.getQuantity()<<"  "<<warehouse.getPrice()<<endl;
        }
 
        file.read(reinterpret_cast<char*>(&warehouse),sizeof(Warehouse));
        
    }
    
    file.clear();
    


}


int InsCode(){

    int code;
    cout<<"\n Inserisci il codice dell oggetto in magazzino : ";
    cin>> code;

    while (code<1||code>10)
    {
        cout<<" \n Codice non disponibile , Ritenta: ";
        cin>>code;
    }
    

    return code;

}
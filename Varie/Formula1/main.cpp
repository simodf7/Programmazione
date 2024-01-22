#include "Championship.h"
#include <iostream>

using std::cout; using std::cin;

int menu();

int main(){

    Championship season2022;

    cout << " - Welcome to F1 season program - \n";
    int request;

    while((request = menu()) != 4){

        switch (request)
        {
        case 0: 
            season2022.insertTeam();
            season2022.insertDriver();
            season2022.insertRace();
            season2022.driverClassification();
            season2022.constructorClass();
            break;

        case 1:
            season2022.printDriverclass();
            break;
        case 2:
            season2022.printConstructorClass();
            break;
        case 3:
            season2022.addNewRace();
            break;
        default:
            std::cerr << "\n Error: Choice not available";
            break;
        
        }

        std::cout << "\n";

    }

    cout << "--- Program terminated";
    return 0;

}


int menu (){

    int n;
    cout << " 0 - Set Races, Drivers and Teams from files \n";
    cout << " 1 - Driver Classification \n";
    cout << " 2 - Constructor Classification \n";
    cout << " 3 - Add new Race \n";
    cout << " 4 - Exit program \n\n";

    cout << "Insert your choice: "; cin >> n;
    return n;
}

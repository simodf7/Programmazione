#include "Championship.h"
#include <algorithm>
#include <fstream>

void Championship::insertDriver(){

    
    std::ifstream dfile("drivers.txt");

    if(!dfile){
        std::cerr << " Driver File could not be opened\n";
        exit(EXIT_FAILURE);
    }

    int id;
    std::string name,surname,team;
    std::string* n = new std::string[3];

    while(!dfile.eof()){
        dfile >> id;
        dfile >> n[0]; // name
        dfile >> n[1]; // surname
        getline(dfile, n[2]); // team  
        drivers.push_back(new Driver(id, n[0], n[1], n[2]));
    }

    dfile.close();
    delete[] n;


    std::sort(drivers.begin(), drivers.end(), [] (Driver* d1, Driver* d2){return (*d1).team < (*d2).team ;});

    int i = 0;
    for(auto j = teams.begin(); j != teams.end(); j++){
        (*j)->drivers.push_back(drivers[i]);
        (*j)->drivers.push_back(drivers[i+1]);
        i += 2;
    }


}





void Championship::insertRace(){


    std::ifstream rfile("races.txt");
    if(!rfile){
        std::cerr << " Race File could not be opened\n";
        exit(EXIT_FAILURE);
    }

    std::string* n = new std::string[2];
    int* s = new int[6];
    std::vector<int> a;
    std::vector<int> b;

    while(!rfile.eof()){
        rfile >> n[0]; // is sprint
        if(n[0] == "No"){
            rfile >> n[1]; // circuit name
            rfile >> s[0]; // id
            rfile >> s[1]; // id2
            rfile >> s[2]; // is 
            rfile >> s[3]; // ic
            rfile >> s[4]; // im
            for(int j=0; j<10; j++){
                rfile >> s[5];
                a.push_back(s[5]);
            }
            // races.push_back(new Race(surname, id, Lap(id2, is, ic,im), a));
            races.push_back(new Race(n[1], s[0], Lap(s[1], s[2], s[3], s[4]), a));

            a = {};
        }
        else {
            rfile >> n[1]; // circuit name
            rfile >> s[1]; // id2
            rfile >> s[2]; // is
            rfile >> s[3]; // ic
            rfile >> s[4];  // im
            for(int j=0; j<10; j++){
                rfile >> s[5];
                a.push_back(s[5]);
            }
            for(int j=0; j<8; j++){
                rfile >> s[5];
                b.push_back(s[5]);
            }
            races.push_back(new SprintRace(n[1], Lap(s[1], s[2], s[3], s[4]), a, b));
            a = {};
            b = {};

        }


    }

    rfile.close();
    delete[] s;
    delete[] n;
        
}

void Championship::insertTeam(){

    std::ifstream tfile("teams.txt");
    if(!tfile){
        std::cerr << " Team File could not be opened\n";
        exit(EXIT_FAILURE);
    }

    std::string team;

    while(!tfile.eof()){
        getline(tfile,team);
        teams.push_back(new Team(team));
    }

    tfile.close();


    teams.sort([] (Team* d1, Team* d2){return (*d1).name < (*d2).name ;});


}


void Championship::driverClassification(){

    static int points[10]{25,18,15,12,10,8,6,4,2,1};
    static int sprintPoints[8]{8,7,6,5,4,3,2,1};

    SprintRace* s;

    for(auto j = races.begin(); j != races.end(); j++){
        s = dynamic_cast<SprintRace*>(*j);
        for(auto i = drivers.begin(); i != drivers.end(); i++){ 

            if(s != nullptr){
                for(int t = 0; t < 8; t++){
                if(s->sprint[t] == (*i)->getNum()){
                    (*i)->points += sprintPoints[t];
                }
                }
            }

            for(int t = 0; t < 10; t++){
                if((*j)->positions[t] == (*i)->getNum()){
                    (*i)->points += points[t];
                    if(t==0) {(*i)->wins+=1;}
                }
            }

            if((*i)->getNum() == (*j)->fastest.getDriver()){
                    (*i)->fast +=1;
                    (*i)->points += 1;
                }

            if((*j)->poleNum == (*i)->getNum()){
                (*i)->poles += 1;
            }
            
            
            
        }
    }

    
    
   std::sort(drivers.begin(), drivers.end(), ([] (Driver* d1, Driver* d2){return (*d1)>(*d2);}));
    
}

void Championship::constructorClass(){

    for(auto j = teams.begin(); j != teams.end(); j++){
        (*j)->nPoints += ((*j)->drivers[0]->points  + (*j)->drivers[1]->points);
        (*j)->nPoles += ((*j)->drivers[0]->poles  + (*j)->drivers[1]->poles);
    }
    
    teams.sort([] (Team* d1, Team* d2){return (*d1)>(*d2);});

}



void Championship::printConstructorClass(){


    std::string request;
    std::cout << "Do you want to print the Constructor Classification in a file also? (Yes or No) "; std::cin >> request;

    std::cout << "\n";

    if(request == "Yes"){

        std::ofstream file("constructorClassification.txt");
        if(!file){
            std::cerr << " File could not be opened\n";
            exit(EXIT_FAILURE);
        }
    
        for(auto i = teams.begin(); i != teams.end(); i++){ 
            std::cout << (*i)->name << " "  << " Points: " << (*i)->nPoints << ", Poles: " << (*i)->nPoles << "\n";
            file << (*i)->name << " "  << " Points: " << (*i)->nPoints << ", Poles: " << (*i)->nPoles << "\n";
        }

        file.close();
    }
    else{
        for(auto i = teams.begin(); i != teams.end(); i++){ 
        std::cout << (*i)->name << " "  << " Points: " << (*i)->nPoints << ", Poles: " << (*i)->nPoles << "\n";
        }

    }
}

void Championship::addNewRace(){


    std::fstream rfile("races.txt", std::ios::app);
    if(!rfile){
        std::cerr << "Race File could not be opened \n";
        exit(EXIT_FAILURE);
    }

    std::string* n = new std::string[2];
    int* s = new int[6];
    std::vector<int> a;
    std::vector<int> b;
    rfile << "\n";

    std::cout << "Is it a Sprint Race? (Yes or No): " ; std::cin >> n[0];  rfile << n[0] << " "; std::cout << "\n";

    if(n[0] == "No"){
        std::cout << "Name of the circuit: "; std::cin.ignore(); std::getline(std::cin, n[1]); rfile << n[1] << " ";  std::cout << "\n";
        std::cout << "Number of pole sitter: "; std::cin >> s[0]; rfile << s[0] << " "; std::cout << "\n";
        std::cout << "Number of fastest lap's driver: " ; std::cin >> s[1]; rfile << s[1] << " "; std::cout << "\n";
        std::cout << "Insert the fastest lap: "; std::cin >> s[2]; std::cin >> s[3]; std::cin >> s[4]; 
        rfile << s[2] << " "; rfile << s[3] << " "; rfile << s[4] <<  " "; std::cout << "\n";
        std::cout << "Insert the result of the race \n";
        for(int j=0; j<10; j++){
            std::cout << j+1 << " Position: "; std::cin >> s[5]; rfile << s[5] << " "; std::cout << "\n";
            a.push_back(s[5]);
        }

        races.push_back(new Race(n[1], s[0], Lap(s[1],s[2],s[3],s[4]), a));

    }
    else{
        std::cout << "Name of the circuit: "; std::cin.ignore(); std::getline( std::cin, n[1]); rfile << n[1] << " "; std::cout << "\n";
        // std::cout << "Number of pole sitter: "; std::cin >> s[0]; rfile << s[0]; std::cout << "\n";
        std::cout << "Number of fastest lap's driver: " ; std::cin >> s[1]; rfile << s[1] << " "; std::cout << "\n";
        std::cout << "Insert the fastest lap: "; std::cin >> s[2]; std::cout << " "; 
        std::cin >> s[3]; std::cout << " "; std::cin >> s[4]; rfile << s[2] << " "; rfile << s[3] << " "; rfile << s[4] <<  " "; std::cout << "\n";
        std::cout << "Insert the result of the race \n";
        for(int j=0; j< 10; j++){
            std::cout << j+1 << " Position: "; std::cin >> s[5]; rfile << s[5] << " "; std::cout << "\n";
            a.push_back(s[5]);
        }
        std::cout << "Insert the result of the sprint race \n";
        for(int j=0; j<8; j++){
            std::cout << j+1 << " Position: "; std::cin >> s[5]; rfile << s[5] << " "; std::cout << "\n";
            b.push_back(s[5]);
        }

        races.push_back(new SprintRace(n[1], Lap(s[1], s[2], s[3], s[4]), a, b));
    }
    


    rfile.close();
    

    
    // for(auto j = races.begin(); j != races.end(); j++){
    //     std::cout << (*j)->circuit << "\n";
    // }
    
    int* points = new int[10]{25,18,15,12,10,8,6,4,2,1};
    int* sprintPoints = new int[8]{8,7,6,5,4,3,2,1};

    if(n[0] == "Yes"){
        for(auto i = drivers.begin(); i != drivers.end(); i++){ 
                for(int t = 0; t < 8; t++){
                    if(b[t] == (*i)->getNum()){
                        (*i)->points += sprintPoints[t];
                    }
                }

                for(int t = 0; t < 10; t++){
                    if(a[t] == (*i)->getNum()){
                        (*i)->points += points[t];
                        if(t==0) {(*i)->wins+=1;}
                    }
                }

                if((*i)->getNum() == s[1]){
                        (*i)->fast +=1;
                        (*i)->points += 1;
                    }
            
        
        }
    }
    else{
        for(auto i = drivers.begin(); i != drivers.end(); i++){ 

                for(int t = 0; t < 10; t++){
                    if(a[t] == (*i)->getNum()){
                        (*i)->points += points[t];
                        if(t==0) {(*i)->wins+=1;}
                    }
                }

                if((*i)->getNum() == s[1]){
                        (*i)->fast +=1;
                        (*i)->points += 1;
                    }

                if(s[0] == (*i)->getNum()){
                    (*i)->poles += 1;
                }
    }


    }

    std::sort(drivers.begin(), drivers.end(), ([] (Driver* d1, Driver* d2){return (*d1)>(*d2);}));


    delete[] n;
    delete[] s;
    delete[] points;
    delete[] sprintPoints;
}


void Championship::printDriverclass(){

    std::string request;
    std::cout << "Do you want to print the Driver Classification in a file also? (Yes or No) "; std::cin >> request;

    std::cout << "\n";

    if(request == "Yes"){

        std::ofstream file("driverClassification.txt");
        if(!file){
            std::cerr << " File could not be opened\n";
            exit(EXIT_FAILURE);
        }
    
        for(auto i = drivers.begin(); i != drivers.end(); i++){ 
            std::cout << (*i)->name << " " << (*i)->surname << " Points: " << (*i)->points << ", Poles: " << (*i)->poles
                << ", Wins: " << (*i)->wins <<  " , Fastest: " << (*i)->fast << "\n"; 
            file << (*i)->name << " " << (*i)->surname << " Points: " << (*i)->points << ", Poles: " << (*i)->poles
                << ", Wins: " << (*i)->wins <<  " , Fastest: " << (*i)->fast << "\n"; 
        }

        file.close();
    }
    else{
        for(auto i = drivers.begin(); i != drivers.end(); i++){ 
            std::cout << (*i)->name << " " << (*i)->surname << " Points: " << (*i)->points << ", Poles: " << (*i)->poles
                << ", Wins: " << (*i)->wins <<  " , Fastest: " << (*i)->fast << "\n";
        }

    }

    
}


Championship::Championship(): races{}, drivers{}, teams{} {}
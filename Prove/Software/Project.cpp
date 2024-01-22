#include "Project.h"


void Project::insertTasks(Task& t){
    for(auto j = tasks.begin(); j!= tasks.end(); j++){
        if(t.getDate() < (*j).getDate()){
            tasks.insert(j, t);
            return;
        }
    }
    tasks.push_back(t);
}


void Project::printTask(){
    for(auto j = tasks.begin(); j!= tasks.end(); j++){
        std::cout << "Task: " << (*j).getHours() << "\n"; 
    }
}

void Project::printProg(){
    for(auto j = programmers.begin(); j!= programmers.end(); j++){
        std::cout << "Programmer: " << (*j).getName() << "\n"; 
    }
}


void Project::insertProg(Programmer& p){
    for(auto j = programmers.begin(); j!= programmers.end(); j++){
        if(p.getcost() < (*j).getcost()){
            programmers.insert(j, p);
            //std::cout << "programmatore inserito\n";
            return;
        }
    }

    programmers.push_back(p);
    //std::cout << "programmatore inserito\n";
}

void Project::workloadDeveloper(){
    int sum{0};
    for(auto j=programmers.begin(); j!= programmers.end(); j++){
        for(auto i = tasks.begin() ; i!=tasks.end(); i++){
            if((*j).getName() == (*i).getProg()->getName()){
                sum += (*i).getHours();
            }
        }
        std::cout << (*j).getName() << ", workload: " << sum << "\n";
        sum = 0;
    }
}
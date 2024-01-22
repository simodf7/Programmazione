#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include "Task.h"
#include <list>
#include <vector>
#include "Date.h"


class Project{

    private:
        std::string name;
        std::string commitent;
        float cost;
        Date start;
        Date end;
        std::list<Task> tasks;
        std::vector<Programmer> programmers;

    public:
        Project(const std::string& n, const std::string& com, float c, const Date& d1, const Date& d2): name{n}, 
        commitent{com}, cost{c}, start{d1}, end{d2}, tasks{}, programmers{} {}
        void insertTasks(Task&);
        void insertProg(Programmer&);
        void printTask();
        void printProg();
        void workloadDeveloper();

};

#endif
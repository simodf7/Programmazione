#include "University.h"


void University::buildHisto(){
    int n{0};
    
   for(auto j = school.begin(); j != school.end(); j++){
        n = (*j).calcCredit();
        for(int i=0; i<histogram.size(); i++){
            if (n==i){
                histogram[i]++;
            }
        }
   }

}

void University::printStudent(){

    for(auto j=school.begin(); j!= school.end(); j++){
        (*j).print();
    }

}


void University::printHisto(){

    for(int i=0; i<histogram.size(); i++){
        std::cout << "H[" << i << "] = " << histogram[i] << "\n";
    }

}



void University::insertStudent(Student& s){
    

    // std::cout << s.calcCredit() << "\n";
     for(auto j=school.begin(); j!= school.end(); j++){
    //     std::cout << (*j).calcCredit() << "\n";
        if(s.calcCredit() < (*j).calcCredit()){
            school.insert(j, s);
            return;
        }
    }


    school.push_back(s);


}

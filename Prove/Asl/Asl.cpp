#include "Asl.h"
#include "algorithm"

void Asl::insertDoctor(const Doctor& d){

    for(auto j = docs.begin(); j!= docs.end(); j++){
        if(d.getSize() < (*j).getSize()){
            docs.insert(j, d);
            return;
        }
    }
    
    docs.push_back(d);
}



void Asl::insertVisit(const Patient& p){

    std::vector<Doctor>::iterator it;
    for(it = docs.begin(); it != docs.end(); it++){
        if(p.getDocName() == it->getName()){
            it->getQueue()->push(p);
            break;
        }
    }


    std::sort(it, docs.end(), [] (const Doctor& lhs, const Doctor& rhs) {return lhs.getSize() < rhs.getSize();} );

    ////// alternativa a sort
    
    // if(it!= docs.end()-1){
    //     for(auto j=it+1; j!=docs.end();j++){
    //         if(j->getSize() < it->getSize()){
    //             Doctor temp = *it;
    //             *it = *j;
    //             *j = temp;
    //         }
    //     }
    // }




}

void Asl::eraseVisit(const Patient& p){

    std::vector<Doctor>::iterator it;
    for(it = docs.begin(); it != docs.end(); it++){
        if(p.getDocName() == it->getName()){
            it->getQueue()->pop();
            break;
        }
    }

    std::sort(docs.begin(), it+1, [] (const Doctor& lhs, const Doctor& rhs) {return lhs.getSize() < rhs.getSize();} );


    // if(it!=dottori.begin()){
    //     for(auto j=dottori.begin();j!=it;j++){
    //         if(j->getVisits().size()>it->getVisits().size()) {
    //             Doctor temp=*it;
    //             *it=*j;
    //             *j=temp;
    //         }
    //     }    

    
    
}

void Asl::printDoc(){

    for(auto j= docs.begin();  j != docs.end(); j++){
        j->print();
        
    }
}





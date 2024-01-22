#include "Ups.h"
#include <typeinfo>


int main(){

    Ups ups;

    Package* p1=new Package{"Alessio","Simone",Date{4,15,2022},15};
    Package* p2=new Package{"Marco","Luca",Date{7,18,2022}, 13.7};
    Package* p3=new Package{"Francesco","Claudio",Date{1,12,2022}, 8.9};
    Package* p4=new Package{"Andrea","Ciro",Date{10,12,2022},90.6};

    Foreign* e1=new Foreign{*p1,"Italia","Europa"};
    Foreign* e2=new Foreign{*p2,"USA","USA"};
    Foreign* e3=new Foreign{*p3,"Brasile","Sud America"};
    Foreign* e4=new Foreign{*p4,"Argentina","Sud America"};


    // std::cout << typeid(*p1).name() << "\n";
    // std::cout << typeid(*p2).name() << "\n";

    ups.insertPackage(*p1);
    ups.insertPackage(*p2);
    ups.insertPackage(*p3);
    ups.insertPackage(*p4);
    ups.insertPackage(*e1);
    ups.insertPackage(*e2);
    ups.insertPackage(*e3);
    ups.insertPackage(*e4);

    std::cout << ups.weekly_earnings();


    ups.findType(e1);
    ups.findType(p1);

    


}

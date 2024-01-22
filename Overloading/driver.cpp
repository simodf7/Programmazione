#include "Date.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    Date d1{1,1,2022};
    Date d2{5,1,2019};

    cout << "\n\n";

    cout<<"d1: "<<d1<<endl;
    cout<<"d2: "<<d2<<endl;
    Date d3=d1+7;
    cout<<"La somma tra d1 e 7: "<<d3<<endl;
    Date d4=20+d2;
    cout<<"La somma tra 20 e d2: "<<d4<<endl;

    if(d1<d2){
        cout<<"d1 is minore di d2"<<endl;
    }
    else{
        cout<<"d1 is maggiore di d2"<<endl;
    }
    if(d1!=d2){
        cout<<"d1 is diverso da d2"<<endl;
    }
    else{
        cout<<"d1 is uguale a d1"<<endl;
    }


    d1+=4;
    cout<<"d1+=4: "<<d1<<endl;;

    d2.operator++();
    cout<<"d2++: "<<d2<<endl;

    Date d5 = d1-20;
    cout<<"d1-20: "<<d5;
}


#include <iostream>
#include <string>
#include "Date.h"


class HeartRates{
public:
  
    HeartRates (std::string f, std::string l, int m, int d, int y)
    : firstName{f}, lastName{l}, birth{m,d,y} {
    };

    void setfirstName(std::string f){
        firstName = f;
    }

    std::string getfirstName() const{
        return firstName;
    }


    void setlastName(std::string l){
        lastName = l;
    }
    
    std::string getlastName() const{
        return lastName;
    }


    void setBirth(int m, int d, int y){
        birth.setDay(d);
        birth.setMonth(m);
        birth.setYear(y);
    }

    void getBirth() {
        birth.displayDate();
    }


    int provideAge(){
        return (2022-(birth.getYear()));
    }

    int maxHeartRate(){
        return(220-provideAge());
    }

    void targetHeartRate(){
        float max{0},min{0};
        min = maxHeartRate()/2;
        max = (maxHeartRate() * 85)/100;
        std::cout << "Target Heart Rate is " << min << "-" << max << " bpm" << std::endl;
    };


private:
    std::string firstName;
    std::string lastName;
    Date birth;
};

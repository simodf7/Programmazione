#include <iostream>
#include "Employee.h"
#include "Date.h"

using std::cout;

int main(){
    Date birth{21,8,1981};
    Date hire{12,4,2014};
    Employee manager{"Jack", "Nicholson", birth , hire};
    


    cout << "\n" << manager.tostring() << "\n";




}
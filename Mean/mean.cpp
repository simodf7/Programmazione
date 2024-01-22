#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;


int main(){
    int numGrades{0};
    float grade;
    float total{0};

    cout << "Enter the number of grades to make the mean: " << endl;
    cin >> numGrades;


    for (int i=0; i<numGrades; i++){
        cout << "Enter the grade: " ;
        cin >> grade;
        total = total + grade;
        cout << endl;
    }

    if (numGrades != 0){
        float mean{total / numGrades};
        cout << "\n The grade mean is: " << mean << setprecision(3) << endl;
        cout << fixed;
    }
    else {cout << "No Grades were entered! ";};
}
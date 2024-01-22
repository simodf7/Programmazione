#include "University.h"



int main(){

    std::cout << "a";
    University uni;
    std::cout << "b";
    Subject s1("Math",9,"Mallozzi");
    Subject s2("Italian",12,"Albertini");
    Subject s3("History",6,"Stimolo");


    Student stu1("Simone", "Di Fraia", "BSBBUSQ");
    Student stu2("Mariano", "Nimao", "MNAIMIN");
    Student stu3("Alfonso", "Canenda", "XIINAO");

    //std::cout << "c";
    stu1.insertSubject(s1);
    //std::cout << "d";
    stu1.insertSubject(s3);
    stu2.insertSubject(s1);
    stu2.insertSubject(s2);
    stu2.insertSubject(s3);
    stu3.insertSubject(s3);

    std::cout << "A";
    uni.insertStudent(stu1);
    uni.insertStudent(stu2);
    uni.insertStudent(stu3);
    std::cout << "B";

    uni.printStudent();
    uni.buildHisto();
    uni.printHisto();

    

}
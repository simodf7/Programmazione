#include "Asl.h"

#include <iostream>



int main()

{

    Asl asl;
    Doctor d1{"Simone","Di Fraia","333444555","SDF"};
    Doctor d2{"Alessio","Cocca","3488397653","CCCLSS01M31F839U"};
    Doctor d3{"Marco","Carta","333444555","CRT"};
    Doctor d4{"Claudio","Mirante","333444555","MRNT"};



    Patient v1{"F","d","2","Simone"};
    Patient v2{"F","d","2", "Simone"};
    Patient v3{"F","d","2", "Simone"};
    Patient v4{"F","d","2","Marco"};
    Patient v5{"F","d","2", "Marco"};
    Patient v6{"F","d","2", "Claudio"};
    Patient v7{"F","d","2","Claudio"};
    //Patient v8{"F","d","2", "Claudio"};



    asl.insertDoctor(d1);
    asl.insertDoctor(d2);
    asl.insertDoctor(d3);
    asl.insertDoctor(d4);

    //asl.printDoc();


    asl.insertVisit(v1);
    asl.insertVisit(v2);
    asl.insertVisit(v3);
    asl.insertVisit(v4);
    asl.insertVisit(v5);
    asl.insertVisit(v6);
    asl.insertVisit(v7);
    //asl.insertVisit(v8);

    asl.printDoc();

    asl.eraseVisit(v1);
    asl.eraseVisit(v2);



    asl.printDoc();

}
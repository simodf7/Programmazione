#include "Eba.h"

Eba::Eba(){

    std::ifstream file("europeanBiscuits.txt", std::ios::in);

    if(!file){
        std::cerr << "File could not be opened\n";
        exit(EXIT_FAILURE);
    }
    //std::cout << "c";
    file >> numBiscuit;


    int l;
    std::string n;
    std::string p;
    std::vector<float> c;
    float s;

    //std::cout << "e";
    for(int i=0; i<numBiscuit; i++){
        file >> l;
        file >> n;
        file >> p;
        std::cout << l << "\n";
        std::cout << n << "\n";
        std::cout << p << "\n";
        //std::cout << "f";
        
        for(int j=0; j<10; j++){
            file >> s;
            std::cout << s << "\n";
            c.push_back(s);
            std::cout << "Vettore: " <<  c[j] <<"\n";
        }
        
        std::cout << "\n";

        //std::cout << "h";
        //std::cout << "d";
        bis.push_back(Biscotto(i,n,p,c));
        c = {};
        
    }

    file.close();

    graph = new std::list<int>[numBiscuit];

}


Eba::~Eba(){
    delete [] graph;
}




float Eba::euclideanDistance(const Biscotto& b1, const Biscotto& b2){
    float sum{0.0};
    //std::cout << "c";
    for(int i=0; i<10;i++){
        //std::cout << "d";
        sum += (b1.getCar()[i] - b2.getCar()[i])*(b1.getCar()[i] - b2.getCar()[i]);
    }
    //std::cout << "e";
    
    return sqrt(sum);
}


void Eba::builtGraph(){

    for(int i=0; i<numBiscuit; i++){
            graph[i].push_back(i);
        
    }


    //std::cout << "a"; 
    for(int i=0; i<numBiscuit; i++){
        for(int j=i+1; j<numBiscuit; j++){
            if(euclideanDistance(bis[i],bis[j]) < EPSILON){
               //std::cout << "b";
                graph[i].push_back(j);
                graph[j].push_back(i);
                //std::cout << "b";
            }
        }
        
    }
    
    
}

void Eba::printGraph(){

    for(int i=0; i<numBiscuit; i++){
        for(auto j = graph[i].begin(); j != graph[i].end(); j++){
            if (j == --graph[i].end()){
                std::cout << *j << "\n";
            }
            else{
                std::cout << *j << "-->" ;
            }
        }
    }
}

void Eba::cluster(int id){

    static int* s = new int[numBiscuit];
    auto cursor = graph[id].begin();

    while(s[*cursor] == 1 && cursor != graph[id].end()){
        ++cursor;
    }

    if(s[*cursor] != 1){
        std::cout << *cursor << "\n";
        s[*cursor] = 1;
        ++cursor;
        cluster(*cursor);
    }

    delete[] s;
    return;

}





bool Eba::checkMarkedList(std::vector<int> s,int i){

    for(auto j = graph[i].begin(); j!= graph[i].end(); j++){
        s[(*j)] != 1;
        return false;
    }
    

    return true;

}


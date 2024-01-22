#ifndef FABRIC_H
#define FABRIC_H

#include <list>
#include "Table.h"
#include "RTable.h"
#include "TTable.h"
#include "RettTable.h"

class Fabric{

    private:
        std::list<Table*> wareHouse;

    public:
        Fabric();
        void insertTable(Table&);
        float summarizeWharehouse();
        void printList();
};



#endif 
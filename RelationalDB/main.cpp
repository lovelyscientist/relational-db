//
//  main.cpp
//  RelationalDB
//
//  Created by xxx on 27.09.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include <iostream>
#include "DataBase.hpp"

int main(int argc, const char * argv[]) {
    Table *myNewTable = new Table(10);
    DataBase *myNewDb = new DataBase();
    
    char dataToAdd[] = "index=3&name=Tanya&surname=Petrova";
    myNewTable->insert(dataToAdd, sizeof(dataToAdd)/sizeof(dataToAdd[0]));
    
    myNewTable->select();
    
    myNewDb->insert_into();
    // insert code here...
    return 0;
}

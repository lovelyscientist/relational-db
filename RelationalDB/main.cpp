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
    std::string columns [500] = {"name", "surname", "age", ""};
    Table* myNewTable = new Table(columns, "people");
    DataBase* myNewDb = new DataBase();
    
    std::string datatoAdd[] = {"skjfsdf", "sdjfhjksf", "sljdfhksdf"};
    
    myNewTable->insert(datatoAdd);
    myNewTable->select();
    myNewDb->start_operation();
    
    return 0;
}

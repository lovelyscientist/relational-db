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
    DataBase* myNewDb = new DataBase();
    myNewDb->start_operation();
    
    return 0;
}

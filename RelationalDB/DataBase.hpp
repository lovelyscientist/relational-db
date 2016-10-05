//
//  DataBase.hpp
//  RelationalDB
//
//  Created by xxx on 04.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#ifndef DataBase_hpp
#define DataBase_hpp
#define MAX_TABLES_COUNT = 100;

#include <stdio.h>
#include "Table.hpp"

class DataBase
{
public:
    explicit DataBase(){
    
    }
    void insert_into();
    void join();
    void select_from();
    int tables_count;
};

#endif /* DataBase_hpp */

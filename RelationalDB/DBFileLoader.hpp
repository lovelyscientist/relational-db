//
//  DBFileLoader.hpp
//  RelationalDB
//
//  Created by xxx on 18.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#ifndef DBFileLoader_hpp
#define DBFileLoader_hpp

#include <stdio.h>
#include "DataBase.hpp"

#endif /* DBFileLoader_hpp */

class DBFileLoader
{
public:
    explicit DBFileLoader(){};
    void create_dump(DataBase*, std::string);
    // void readTableFromFile()
    DataBase* restore_db(DataBase*, std::string);
};

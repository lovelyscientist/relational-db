//
//  DBFileLoader.cpp
//  RelationalDB
//
//  Created by xxx on 18.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "DBFileLoader.hpp"
#include "DataBase.hpp"

void DBFileLoader::create_dump(DataBase dbToDump, std::string fileName) {
    
}

DataBase DBFileLoader::restore_db(std::string fileName) {
    return *new DataBase();
}

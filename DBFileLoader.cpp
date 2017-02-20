//
//  DBFileLoader.cpp
//  RelationalDB
//
//  Created by xxx on 18.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "DBFileLoader.hpp"
#include "DataBase.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void DBFileLoader::create_dump(DataBase* dbToDump, std::string fileName) {
    std::ofstream outfile(fileName, std::iostream::out);
    
    outfile << *dbToDump;
}

void DBFileLoader::restore_db(DataBase* db, std::string fileName) {
    std::ifstream infile(fileName, std::iostream::in);
    
    infile >> *db;
}

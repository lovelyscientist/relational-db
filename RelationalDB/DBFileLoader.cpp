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

void DBFileLoader::create_dump(DataBase* dbToDump, std::string fileName) {
    std::ofstream outfile;
    outfile.open("dump.txt");
    
    // write inputted data into the file.
    outfile << dbToDump->get_name() << std::endl;
    
    for (unsigned int i = 0; i < dbToDump->get_tables_count(); i++) {
        outfile << "*" << std::endl;
        outfile << dbToDump->tables[i].get_name() << std::endl;
        for (unsigned int j = 0; j< dbToDump->tables[i].get_columns_length(); ++j) {
            outfile << "*" << std::endl;
            outfile << dbToDump->tables[i].get_columns()[j] << std::endl;
        }
    }
    
    outfile.close();
}

DataBase DBFileLoader::restore_db(std::string fileName) {
    return *new DataBase();
}

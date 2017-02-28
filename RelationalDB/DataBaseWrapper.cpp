//
//  DataBaseWrapper.cpp
//  RelationalDB
//
//  Created by xxx on 21.02.17.
//  Copyright © 2017 xxx. All rights reserved.
//

#include "DataBaseWrapper.hpp"
#include <fstream>

void DBSmartPointer::create_dump(DataBase* db, std::string fileName) {
    std::ofstream outfile(fileName, std::iostream::out);
    
    outfile << "tables_count: " << db->get_tables_count() << std::endl;
    outfile << "tables: " << std::endl;
    
    for (int i = 0; i<db->get_tables_count(); i++) {
        outfile << db->tables[i].get_name() << std::endl;
    }
}
DBSmartPointer::~DBSmartPointer() {
    if (this->db_pointer) {
        delete this->db_pointer;
    }
}

DataBase* DBSmartPointer::operator -> ()
{
    return this->db_pointer;
}
DataBase& DBSmartPointer::operator * ()
{
    return *this->db_pointer;
}
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
    //DataBase* BooksDb = new DataBase("Books");
    //BooksDb->start_operation();
    
    
    DataBase* ISSDB = new DataBase("ISS");
    ISSDB->create_table("CREATE TABLE modules (title_of_module,id_of_agency);");
    ISSDB->create_table("CREATE TABLE agencies (title_of_agency,id);");
    
    ISSDB->insert_into("INSERT INTO modules VALUES (Zarya,4);");
    ISSDB->insert_into("INSERT INTO modules VALUES (Unity,1);");
    ISSDB->insert_into("INSERT INTO modules VALUES (Columbus,2);");
    ISSDB->insert_into("INSERT INTO modules VALUES (Cupola,3);");
    
    ISSDB->insert_into("INSERT INTO agencies VALUES (NASA,1);");
    ISSDB->insert_into("INSERT INTO agencies VALUES (ESA,2);");
    ISSDB->insert_into("INSERT INTO agencies VALUES (JAXA,3);");
    ISSDB->insert_into("INSERT INTO agencies VALUES (Roskosmos,4);");
    ISSDB->insert_into("INSERT INTO agencies VALUES (CSA,5);");
   
    ISSDB->join("INNER JOIN modules AND agencies ON modules.id_of_agency = agencies.id");
    
    
    //DBFileLoader *loader = new DBFileLoader();
    //loader->create_dump(SchoolDB, "file");
    return 0;
}

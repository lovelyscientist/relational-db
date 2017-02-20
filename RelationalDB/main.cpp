//
//  main.cpp
//  RelationalDB
//
//  Created by xxx on 27.09.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include <iostream>
#include "DBFileLoader.hpp"

int main(int argc, const char * argv[]) {
    //DataBase* BooksDb = new DataBase("Books");
    //BooksDb->start_operation();
    
    
    DataBase ISSDB("ISS");
    
    DataBase iss_new("new");
    
    ISSDB.get_operation_title("CREATE TABLE modules (title_of_module,id_of_agency);")
         .get_operation_title("CREATE TABLE agencies (title_of_agency,id);")
         .get_operation_title("INSERT INTO modules VALUES (Zarya,4);")
         .get_operation_title("INSERT INTO modules VALUES (Unity,1);")
         .get_operation_title("INSERT INTO modules VALUES (Columbus,2);")
         .get_operation_title("INSERT INTO modules VALUES (Cupola,3);")
         .get_operation_title("INSERT INTO agencies VALUES (NASA,1);")
         .get_operation_title("INSERT INTO agencies VALUES (ESA,2);")
         .get_operation_title("INSERT INTO agencies VALUES (JAXA,3);")
         .get_operation_title("INSERT INTO agencies VALUES (Roskosmos,4);")
         .get_operation_title("INSERT INTO agencies VALUES (CSA,5);")
         .get_operation_title("INNER JOIN modules AND agencies ON modules.id_of_agency = agencies.id");
    
    std::cout << ISSDB;
    
    DBFileLoader loader;
    loader.create_dump(&ISSDB, "dump.txt");
    
    loader.restore_db(&iss_new, "backup.txt");
    
    std::cout << iss_new;
    
    ISSDB.start_operation();
    
    return 0;
}

//
//  main.cpp
//  RelationalDB
//
//  Created by xxx on 27.09.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include <iostream>
#include "DataBaseWrapper.hpp"


int main(int argc, const char * argv[]) {
    DataBase ISSDB("ISS");
    DataBase TestDialog("TEST1");
    DataBase TestRestore;
    DataBase TestAssignment("TEST2");
    DBSmartPointer smart_p;
    DataBase TestPseudoVariable("test");
    
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
    loader.restore_db(&TestRestore, "backup.txt");
    
    TestAssignment = ISSDB;
    std::cout << TestAssignment;
    
    DataBase TestCopyConstructor(ISSDB);
    std::cout << TestCopyConstructor;
    
    // testing pseudo variable
    
    std::string arr[3];
    
    for (int i = 0; i < 3; i++) {
        arr[i] = "a" + std::to_string(i);
    }
    
   
    TestPseudoVariable
        .get_operation_title("CREATE TABLE modules (title_of_module,id_of_agency);")
        .get_operation_title("CREATE TABLE friends (title_of_module,id_of_agency);")
        .get_operation_title("CREATE TABLE lollypops (title_of_module,id_of_agency);")
        .get_operation_title("CREATE TABLE fruits (title_of_module,id_of_agency);");
    
    
    TestPseudoVariable(1,2) = Table(arr, "letters");
    
    smart_p.create_dump(&TestPseudoVariable, "myfile.txt");
    
    TestDialog.start_operation();
    
    return 0;
}

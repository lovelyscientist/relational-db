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
    DataBase* BooksDb = new DataBase("Books");
    
    /*
    DataBase* SchoolDB = new DataBase("School");
    SchoolDB->create_table("CREATE TABLE boys (name,surname,age);");
    SchoolDB->create_table("CREATE TABLE girls (name,surname,favourite_color);");
    SchoolDB->insert_into("INSERT INTO boys VALUES (vlad,sazonov,19);");
    SchoolDB->insert_into("INSERT INTO boys VALUES (vlad,alexashin,19);");
    SchoolDB->insert_into("INSERT INTO girls VALUES (inna,sherbak,19);");
    SchoolDB->insert_into("INSERT INTO girls VALUES (vlada,tyshchenko,19);");
    
    DBFileLoader *loader = new DBFileLoader();
    loader->create_dump(SchoolDB, "file");*/

    BooksDb->start_operation();
    return 0;
}

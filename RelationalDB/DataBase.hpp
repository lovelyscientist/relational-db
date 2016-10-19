//
//  DataBase.hpp
//  RelationalDB
//
//  Created by xxx on 04.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#ifndef DataBase_hpp
#define DataBase_hpp
#define MAX_TABLES_COUNT 100
#define INSERT_QUERY_NAME "INSERT"
#define SELECT_QUERY_NAME "SELECT"
#define CREATE_TABLE_QUERY_NAME "CREATE TABLE"
#define INNER_JOIN_QUERY_NAME "INNER JOIN"
#define SELECT_QUERY_NAME "SELECT * FROM"
#define CREATE_DUMP_QUERY_NAME "CREATE DUMP"

#include <stdio.h>
#include "Table.hpp"

class DataBase
{
public:
    DataBase (std::string);
    void start_operation();
    void insert_into(std::string);
    void join(std::string);
    void select_from(std::string);
    void create_table(std::string);
    int get_tables_count();
    std::string get_name();
    std::string* split_to_array(std::string, char);
    std::string parse_join(std::string, std::string);
    Table tables[MAX_TABLES_COUNT];
private:
    std::string name;
    int tables_count = 0;
};

#endif /* DataBase_hpp */

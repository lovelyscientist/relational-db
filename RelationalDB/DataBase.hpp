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
#define QUIT_QUERY_NAME "QUIT;"
#define CREATE_DUMP_QUERY_NAME "CREATE DUMP"
#define RESTORE_QUERY_NAME "RESTORE"

#include <stdio.h>
#include "Table.hpp"

class DataBase
{
public:
    DataBase (std::string);
    DataBase(DataBase &);
    void start_operation();
    void set_name(std::string);
    DataBase& get_operation_title(std::string);
    void insert_into(std::string);
    void join(std::string);
    void select_from(std::string);
    void create_table(std::string);
    void create_dump(std::string);
    void restore_db(std::string);
    int get_tables_count();
    Table& operator[] (const int);
    DataBase& operator= (DataBase&);
    DataBase(const DataBase&);
    std::string get_name();
    std::string* split_to_array(std::string, char);
    std::string parse_join(std::string, std::string);
    Table tables[MAX_TABLES_COUNT];
    friend std::ostream& operator <<(std::ostream&, DataBase&);
    friend std::istream& operator >>(std::istream&, DataBase&);
private:
    std::string name;
    std::string sql_statements[1000];
    int sql_statements_real_length = 0;
    int tables_count = 0;
};

#endif /* DataBase_hpp */

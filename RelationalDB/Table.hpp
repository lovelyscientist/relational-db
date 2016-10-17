//
//  Table.hpp
//  RelationalDB
//
//  Created by xxx on 02.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp
#define ROW_SIZE 50
#define MAX_TABLE_NAME_SIZE 100
#include <stdio.h>
#include <iostream>
#include <string.h>
#endif /* Table_hpp */

class Table
{
public:
    explicit Table(std::string [], std::string);
    Table() {};
    void insert(std::string []);
    void join();
    void select();
    unsigned int data_length = 0;
    unsigned int columns_length = 0;
    std::string name;
    std::string** data;
    std::string* columns;
private:
    int length_;
};

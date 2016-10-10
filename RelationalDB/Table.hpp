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
#include "String.hpp"
#endif /* Table_hpp */

class Table
{
public:
    explicit Table(int length, String columns) :columns(columns){
        this->columns = columns;
        this->columns.print();
        data = new char * [length]; // could be entered during runtime
        data[0] = new char[ROW_SIZE];
        data[1]= new char[ROW_SIZE];
        strcpy(data[0], "index=1&name=Ivan&surname=Ivanov");
        strcpy(data[1], "index=2&name=Sergii&surname=Sergiev");
        length_ = 2;
    }
    char** data;
    void insert(char [], int);
    void join();
    void select();
    char name[MAX_TABLE_NAME_SIZE];
    String columns;
private:
    int length_;
};

//
//  Table.cpp
//  RelationalDB
//
//  Created by xxx on 02.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "Table.hpp"
#include <iostream>
#include <stdlib.h>

Table::Table(std::string columns_[], std::string name) {
    this->data = new std::string*[100];
    this->columns = new std::string[500];
    this->name = name;
    unsigned int length = 0;
    
    for (length = 0; columns_[length].length(); length++) {
        this->columns[length] = columns_[length];
    }
    
    this->columns_length = length;
    this->data_length = 0;
}
std::string Table::get_name() {
    return this->name;
}
std::string* Table::get_columns() {
    return this->columns;
}
std::string** Table::get_data() {
    return this->data;
}
void Table::set_data(std::string ** db_data) {
    for (int i = 0; i < this->data_length; ++i ){
       this->data[i] = db_data[i];
    }
}
void Table::insert(std::string row[])
{
    this->data[this->data_length] = row;
    this->data_length++;
}
void Table::select()
{
    for (unsigned int i = 0; i < this->data_length; ++i ){
        for (unsigned int j = 0; this->columns[j].length(); ++j ){
            std::cout << this->data[i][j] + " ";
        }
        std::cout << "" << std::endl;
    }
}
unsigned int Table::get_data_length() {
    return this->data_length;
}
unsigned int Table::get_columns_length() {
    return this->columns_length;
}

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
    
    
    for (unsigned int length = 0; columns_[length].length(); length++) {
        this->columns[length] = columns_[length];
    }
    
    this->columns_length = length_- 1;
    
    data[0] = new std::string[3] {"Alexey", "Ivanov", "23"};
    data[1] = new std::string[3] {"Artem", "Ivanov", "20"};
    data[2] = new std::string[3] {"Ivan", "Ivanov", "33"};
    
    this->data_length = 3;
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
void Table::insert(std::string row[])
{
    this->data[this->data_length] = row;
    
    //this->data[this->data_length] = new std::string [this->columns_length] ();
    //for (unsigned int j = 0; this->columns_length; ++j ){
      //  this->data[this->data_length][j] = row[j];
        //std::cout << this->data[this->data_length][j] << std::endl;
    //}
    
    this->data_length++;
}
void Table::select()
{
    for (unsigned int j = 0; this->columns[j].length(); ++j ){
        std::cout << this->columns[j] + " ";
    }
    
    std::cout << "\n---------------" << std::endl;
    
    for (unsigned int i = 0; i < this->data_length; ++i ){
        for (unsigned int j = 0; this->columns[j].length(); ++j ){
            std::cout << this->data[i][j] + " ";
        }
        std::cout << "" << std::endl;
    }

}
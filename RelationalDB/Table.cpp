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
    
    
    for (int length = 0; columns_[length].length(); length++) {
        this->columns[length] = columns_[length];
    }
    
    data[0] = new std::string[3] {"Alexey", "Ivanov", "23"};
    data[1] = new std::string[3] {"Artem", "Ivanov", "20"};
    data[2] = new std::string[3] {"Ivan", "Ivanov", "33"};
}
void Table::join()
{
    std::cout << "successful join" << std::endl;
}
void Table::insert(std::string row[])
{
    
}
void Table::select()
{
    for (int j = 0; this->columns[j].length(); ++j ){
        std::cout << this->columns[j] + " ";
    }
    
    std::cout << "\n---------------" << std::endl;
    
    for (int i = 0; i < 3; ++i ){
        for (int j = 0; j < 3; ++j ){
            std::cout << this->data[i][j] + " ";
        }
        std::cout << "" << std::endl;
    }

}
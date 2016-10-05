//
//  Table.cpp
//  RelationalDB
//
//  Created by xxx on 02.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "Table.hpp"
#include <iostream>

void Table::join()
{
    std::cout << "successful join" << std::endl;
}
void Table::insert(char newData[],int newDataLength)
{
    data[length_] = new char[newDataLength];
    strcpy(data[length_], newData);
    ++length_;
}
void Table::select()
{
    char ampersant[] = "&",
         *p = &(ampersant[0]);
   
    for (int i=0; i<length_; ++i){
        for (int j=0; j< ROW_SIZE; ++j) {
            if (data[i][j] == *p) {
                std::cout << "" << std::endl;
            } else {
                std::cout << data[i][j];
            }
        }
        std::cout << "\n--------------------------------------\n";

    }
}
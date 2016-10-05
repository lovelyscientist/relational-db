//
//  DataBase.cpp
//  RelationalDB
//
//  Created by xxx on 04.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "DataBase.hpp"
#include <iostream>

void DataBase::join()
{
    std::cout << "successful join" << std::endl;
}
void DataBase::insert_into()
{
    char dataToBeInserted[ROW_SIZE];
    char partialData[ROW_SIZE];
    const char select[7] = "SELECT";
    const char insert[7] = "INSERT";
    const char columnsStart[2] = "(";
    
    printf("Please, enter you SQL request:\n");
    scanf("%[^\n]s", dataToBeInserted);
    printf(dataToBeInserted);
    strncpy(partialData, dataToBeInserted, 6);
    
    if (strcmp(select, partialData) == 0) {
        printf("it is select\n");
    }
    
    if (strcmp(insert, partialData) == 0) {
        printf("it is insert\n");
    }
    
    /*for (int i=0; i<ROW_SIZE; i++){
        if (strcmp(dataToBeInserted + 6, &columnsStart[0]) == 0) {
            printf("it is column start and i is %d", i);
            break;
        }

    }*/
    
}
void DataBase::select_from()
{
    
}
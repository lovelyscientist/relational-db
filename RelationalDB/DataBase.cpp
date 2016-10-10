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
    
    String select = String(SELECT_QUERY_NAME);
    String insert = String(INSERT_QUERY_NAME);
    
    printf("Please, enter you SQL request:\n");
    scanf("%[^\n]s", dataToBeInserted);

    String queryName = String(dataToBeInserted).substring(0, 6);
    
    if (queryName == select) {
        printf("it is select\n");
    }
    
    if (queryName == insert) {
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
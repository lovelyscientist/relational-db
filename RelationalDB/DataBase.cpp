//
//  DataBase.cpp
//  RelationalDB
//
//  Created by xxx on 04.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "DataBase.hpp"
#include <iostream>

void DataBase::start_operation()
{
    std::string dataToBeInserted,
                shortQueryName,
                longQueryName;
    
    bool isValidOperation = false;
    
    printf("Please, enter you SQL request:\n");
    //std::getline (std::cin, dataToBeInserted);
    
    while (std::getline (std::cin, dataToBeInserted)) {
        shortQueryName = dataToBeInserted.substr(0, 6);
        longQueryName = dataToBeInserted.substr(0, 12);
        
        
        if (shortQueryName == SELECT_QUERY_NAME) {
            isValidOperation = true;
            this->select_from();
        }
        
        if (shortQueryName == INSERT_QUERY_NAME) {
            isValidOperation = true;
            this->insert_into();
        }
        
        if (longQueryName == CREATE_TABLE_QUERY_NAME) {
            isValidOperation = true;
            this->create_table(dataToBeInserted);
        }
        
        if (!isValidOperation) std::cout << "Oops! This operation can not be performed" << std::endl;
        isValidOperation = false;
    }
    
}

void DataBase::create_table(std::string inputData)
{
    std::string columns = "";
    std::size_t positionOf1, positionOf2, positionOfSpace;
    
    positionOf1 = inputData.find('(');
    positionOf2 = inputData.find(';');
    positionOfSpace = inputData.find(' ', 13);
    
    columns = inputData.substr(positionOf1 + 1, positionOf2-positionOf1-2);
    this->tables[this->tables_count] = Table(this->split_to_array(columns, ','), inputData.substr(13, positionOfSpace - 12));
    std::cout << "successful creation of " + this->tables[this->tables_count].name << std::endl;
    this->tables_count++;
}

void DataBase::join()
{
    std::cout << "successful join" << std::endl;
}

void DataBase::insert_into()
{
    std::cout << "successful insert" << std::endl;
}
void DataBase::select_from()
{
    std::cout << "successful select" << std::endl;
}
std::string* DataBase::split_to_array(std::string string, char delim) {
    std::string arr[500];
    std::size_t spacePos, currPos = 0, prevPos = 0;;
    int k = 0;
    
    while (string.find(delim, currPos) != std::string::npos) {
        spacePos = string.find(delim,currPos);
        currPos = spacePos;
        arr[k] = string.substr(prevPos, currPos - prevPos);
        currPos++;
        prevPos = currPos;
        k++;
    }
    
    arr[k] = string.substr(prevPos,string.length());
    arr[k+1] = "";

    return &arr[0];
}



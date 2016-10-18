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
                longQueryName,
                middleQueryName,
                longLongQueryName;
    
    bool isValidOperation = false;
    
    printf("Please, enter you SQL request:\n");
    
    while (std::getline (std::cin, dataToBeInserted)) {
        shortQueryName = dataToBeInserted.substr(0, 6);
        middleQueryName = dataToBeInserted.substr(0, 10);
        longQueryName = dataToBeInserted.substr(0, 12);
        longLongQueryName = dataToBeInserted.substr(0, 13);
        
        
        if (shortQueryName == SELECT_QUERY_NAME) {
            isValidOperation = true;
            //this->select_from("sasha");
        }
        
        if (shortQueryName == INSERT_QUERY_NAME) {
            isValidOperation = true;
            this->insert_into(dataToBeInserted);
        }
        
        if (longQueryName == CREATE_TABLE_QUERY_NAME) {
            isValidOperation = true;
            this->create_table(dataToBeInserted);
        }
        
        if (middleQueryName == INNER_JOIN_QUERY_NAME) {
            isValidOperation = true;
            this->join(dataToBeInserted);
        }
        
        if (longLongQueryName == SELECT_QUERY_NAME) {
            isValidOperation = true;
            this->select_from(dataToBeInserted);
        }
        
        if (!isValidOperation) std::cout << "Oops! This operation can not be performed" << std::endl;
        isValidOperation = false;
    }
    
}

void DataBase::create_table(std::string inputData)
{
    std::string columns = "";
    std::size_t positionOfBegin, positionOfEnd, positionOfSpace;
    
    positionOfBegin = inputData.find('(');
    positionOfEnd = inputData.find(';');
    positionOfSpace = inputData.find(' ', 13);
    
    columns = inputData.substr(positionOfBegin + 1, positionOfEnd-positionOfBegin-2);
    this->tables[this->tables_count] = Table(this->split_to_array(columns, ','), inputData.substr(13, positionOfSpace - 13));
    std::cout << "successful creation of " + this->tables[this->tables_count].get_name() << std::endl;
    this->tables_count++;
}

void DataBase::join(std::string inputData)
{
    Table tableObj;
    std::string table1 = this->parse_join(inputData, "table1");
    std::string table2 = this->parse_join(inputData, "table2");
    std::string column1 = this->parse_join(inputData, "column1");
    std::string column2 = this->parse_join(inputData, "column2");
    
    for (unsigned int i = 0; i<this->tables_count; i++){
        if (this->tables[i].get_name() == table1) {
            tableObj = this->tables[i];
            break;
        }
    }
    
    for (unsigned int i = 0; i<this->tables_count; i++){
        if (this->tables[i].get_name() == table2) {
            break;
        }
    }
}

void DataBase::insert_into(std::string inputData)
{
    std::string values = "",
                name = "";
    
    std::size_t positionOf1,
                positionOf2,
                positionOfSpace;
    
    positionOf1 = inputData.find('(');
    positionOf2 = inputData.find(';');
    positionOfSpace = inputData.find(' ', 12);
    
    values = inputData.substr(positionOf1 + 1, positionOf2-positionOf1-2);
    name = inputData.substr(12, positionOfSpace - 12);
    
    for (unsigned int i = 0; i<this->tables_count; i++){
        if (this->tables[i].get_name() == name) {
            this->tables[i].insert(this->split_to_array(values, ','));
            std::cout << "successful insert" << std::endl;
            break;
        }
    }
}
void DataBase::select_from(std::string inputData)
{
    std::string tableName = inputData.substr(14, inputData.length() - 15);
    
    for (unsigned int i = 0; i<this->tables_count; i++){
        if (this->tables[i].get_name() == tableName) {
            this->tables[i].select();
            std::cout << "successful select from " + tableName << std::endl;
            break;
        }
    }
}
std::string* DataBase::split_to_array(std::string string, char delim) {
    std::string* arr = new std::string [500];
    std::size_t spacePos, currPos = 0, prevPos = 0;;
    unsigned int k = 0;
    
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
std::string DataBase:: parse_join(std::string inputData, std::string returnParametr){
    std::string table1 = "",
                table2 = "",
                column1 = "name",
                column2 = "name";
    
    std::size_t positionOfSpace1,
                positionOfSpace2,
                positionOfSpace3;
    
    positionOfSpace1 = inputData.find(' ', 11);
    positionOfSpace2 = inputData.find(' ', positionOfSpace1 + 4);
    positionOfSpace3 = inputData.find("ON", positionOfSpace2 + 1);
    
    table1 = inputData.substr(11, positionOfSpace1 - 10);
    table2 = inputData.substr(positionOfSpace2 + 1, positionOfSpace3 - positionOfSpace2 - 2);
    
    if (returnParametr == "table1") return table1;
    if (returnParametr == "table2") return table2;
    if (returnParametr == "column1") return column1;
    if (returnParametr == "column2") return column2;
    else return "";
}



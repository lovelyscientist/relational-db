//
//  DataBase.cpp
//  RelationalDB
//
//  Created by xxx on 04.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "DataBase.hpp"
#include "DBFileLoader.hpp"

#include <iostream>
#include <map>

DataBase::DataBase(std::string name){
    this->name = name;
};
DataBase::DataBase(){
    this->name = "";
};
void DataBase::set_name(std::string name){
    this->name = name;
};
std::ostream& operator<<(std::ostream& os, DataBase& db)
{
    os << db.name << std::endl;
    for (int i = 0; i < db.sql_statements_real_length; i++) {
        os << db.sql_statements[i] << std::endl;
    }

  return os;
}
std::istream& operator >>(std::istream& is, DataBase& db)
{
    std::string line, query, name;
    
    std::getline(is, name);
    db.set_name(name);
    
    while (std::getline(is, query))
    {
        db.get_operation_title(query);
    }
    
    return is;
}
Table& DataBase::operator[] (const int index)
{
    return this->tables[index];
}
DataBase& DataBase::operator= (DataBase& db) {
    if (this != &db) {
        this->name = db.name;
        
        for (int i = 0; i < db.tables_count; i++){
            this->tables[i] = Table(db[i].get_columns(), db[i].get_name());
            this->tables[i].set_data(db[i].get_data());
        }
        
        for (int i = 0; i < db.sql_statements_real_length; i++) {
            this->sql_statements[i] = db.sql_statements[i];
        }
        
        this->tables_count = db.get_tables_count();
        this->sql_statements_real_length = db.sql_statements_real_length;
    
    }
    
    return *this;
}

DataBase::DataBase(DataBase & db) {
    if (this != &db) {
        this->name = db.name;
        
        for (int i = 0; i < db.tables_count; i++){
            this->tables[i] = Table(db[i].get_columns(), db[i].get_name());
            this->tables[i].set_data(db[i].get_data());
        }
        
        for (int i = 0; i < db.sql_statements_real_length; i++) {
            this->sql_statements[i] = db.sql_statements[i];
        }
        
        this->tables_count = db.get_tables_count();
        this->sql_statements_real_length = db.sql_statements_real_length;
        
    }
}
int DataBase::get_tables_count(){
    return this->tables_count;
}
std::string DataBase::get_name(){
    return this->name;
}
DataBase& DataBase::get_operation_title(std::string dataToBeInserted) {
    std:: string shortQueryName = dataToBeInserted.substr(0, 6),
                 shortMiddleQueryName = dataToBeInserted.substr(0, 7),
                 middleQueryName = dataToBeInserted.substr(0, 10),
                 middleMiddleQueryName = dataToBeInserted.substr(0, 11),
                 longQueryName = dataToBeInserted.substr(0, 12),
                 longLongQueryName = dataToBeInserted.substr(0, 13);
    
    bool isValidOperation = false,
         saveToSQLCommansCollection = true;
    
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
        saveToSQLCommansCollection = false;
        this->select_from(dataToBeInserted);
    }
    
    if (middleMiddleQueryName == CREATE_DUMP_QUERY_NAME) {
        isValidOperation = true;
        saveToSQLCommansCollection = false;
        this->create_dump(dataToBeInserted);
    }
    
    if (shortMiddleQueryName == RESTORE_QUERY_NAME) {
        isValidOperation = true;
        saveToSQLCommansCollection = false;
        this->restore_db(dataToBeInserted);
    }

    
    if (isValidOperation && saveToSQLCommansCollection) {
        this->sql_statements[sql_statements_real_length] = dataToBeInserted;
        this->sql_statements_real_length++;
    }
    
    
    if (!isValidOperation) std::cout << "Oops! This operation can not be performed" << std::endl;
    
    return *this;

}
void DataBase::start_operation()
{
    std:: string dataToBeInserted;
    printf("Please, enter you SQL request:\n");
    
    while (std::getline (std::cin, dataToBeInserted)) {
        if (dataToBeInserted == QUIT_QUERY_NAME) {
            break;
        }
        this->get_operation_title(dataToBeInserted);
    }
    
}
void DataBase::restore_db(std::string inputData)
{
    DBFileLoader *loader = new DBFileLoader();
    
    std::size_t beginningOfFileName = 8;
    std::string fileName = inputData.substr(beginningOfFileName);
    
    loader->restore_db(this, fileName);
    
    std::cout << "successfully created dump for " + this->name << std::endl;
}
void DataBase::create_dump(std::string inputData)
{
    DBFileLoader *loader = new DBFileLoader();
    
    std::size_t beginningOfFileName = 12;
    std::string fileName = inputData.substr(beginningOfFileName, inputData.length() - 13);
    
    loader->create_dump(this, fileName);
    
    std::cout << "successfully created dump for " + this->name << std::endl;
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
    std::map<std::string, std::string> shorterTable;
    
    Table tableObj1,
          tableObj2,
          tableForMap;
    
    int indexOfKeyColumn = 0;
    int indexOfSearchColumn = 0;
    
    std::string table1 = this->parse_join(inputData, "table1"),
                table2 = this->parse_join(inputData, "table2"),
                column1 = this->parse_join(inputData, "column1"),
                column2 = this->parse_join(inputData, "column2"),
                tmpColumn;
    
    for (unsigned int i = 0; i<this->tables_count; i++){
        if (this->tables[i].get_name() == table1) tableObj1 = this->tables[i];
        if (this->tables[i].get_name() == table2) tableObj2 = this->tables[i];
    }
    
    if (tableObj1.get_data_length() >= tableObj2.get_data_length()) {
        tableForMap = tableObj2;
        tableObj2 = tableObj1;
        tmpColumn = column1;
        column1 = column2;
        column2 = tmpColumn;
    } else {
        tableForMap = tableObj1;
    }
    
    // replace this method to Table class
    
    for (int i = 0; i<tableForMap.get_columns_length(); i++) {
        if (tableForMap.get_columns()[i] == column1) {
            indexOfKeyColumn = i;
            break;
        }
    }
    
    for (int i = 0; i<tableObj2.get_columns_length(); i++) {
        if (tableObj2.get_columns()[i] == column2) {
            indexOfSearchColumn = i;
            break;
        }
    }
    
    // building map started
    for (int i = 0; i < tableForMap.get_data_length(); ++i) {
        std::string valueOfMap = "";
        for (int j = 0; j <tableForMap.get_columns_length(); ++j) {
            if (j != indexOfKeyColumn) {
                valueOfMap+=tableForMap.get_data()[i][j] + " ";
            }
        }
        shorterTable[tableForMap.get_data()[i][indexOfKeyColumn]] = valueOfMap;
    }
    
     // building map ended
    
    for (int i = 0; i < tableObj2.get_data_length(); i++) {
        if (shorterTable.count(tableObj2.get_data()[i][indexOfSearchColumn]) > 0) {
            for (int j = 0; j < tableObj2.get_columns_length(); j++) {
                std::cout << tableObj2.get_data()[i][j] + " ";
            }
            std::cout << shorterTable.at(tableObj2.get_data()[i][indexOfSearchColumn]) << std::endl;
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
            std::cout << "successful insert into " + name << std::endl;
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

    return arr;
}
std::string DataBase:: parse_join(std::string inputData, std::string returnParametr){
    std::string table1 = "",
                table2 = "",
                column1 = "id_of_agency",
                column2 = "id";
    
    std::size_t positionOfSpace1,
                positionOfSpace2,
                positionOfSpace3;
    
    positionOfSpace1 = inputData.find(' ', 11);
    positionOfSpace2 = inputData.find(' ', positionOfSpace1 + 4);
    positionOfSpace3 = inputData.find("ON", positionOfSpace2 + 1);
    
    table1 = inputData.substr(11, positionOfSpace1 - 11);
    table2 = inputData.substr(positionOfSpace2 + 1, positionOfSpace3 - positionOfSpace2 - 2);
    
    if (returnParametr == "table1") return table1;
    if (returnParametr == "table2") return table2;
    if (returnParametr == "column1") return column1;
    if (returnParametr == "column2") return column2;
    else return "";
}



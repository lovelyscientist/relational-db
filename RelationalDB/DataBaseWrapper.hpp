//
//  DataBaseWrapper.hpp
//  RelationalDB
//
//  Created by xxx on 21.02.17.
//  Copyright © 2017 xxx. All rights reserved.
//

#ifndef DataBaseWrapper_hpp
#define DataBaseWrapper_hpp

#include <stdio.h>
#include "DBFileLoader.hpp"

class DBSmartPointer : DBFileLoader {
public:
    ~DBSmartPointer();
    DataBase& operator *  ();
    DataBase* operator -> ();
    void create_dump(DataBase*, std::string);
private:
    DataBase* db_pointer;
};

#endif /* DataBaseWrapper_hpp */

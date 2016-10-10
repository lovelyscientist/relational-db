//
//  Row.hpp
//  RelationalDB
//
//  Created by xxx on 10.10.16.
//  Copyright © 2016 xxx. All rights reserved.
//

#ifndef Row_hpp
#define Row_hpp

#include <stdio.h>
#include "String.hpp"

#endif /* Row_hpp */

class Row {
public:
    Row(String);
    ~Row();
    String values[];
};
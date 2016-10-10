//
//  String.hpp
//  RelationalDB
//
//  Created by Andrii Selivanov on 10/5/16.
//  Copyright © 2016 xxx. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>

#endif /* String_hpp */

class String {
    
public:
    char *cString;
    bool operator ==(const String &rhs);
    int getLength(const char *);
    void print();
    String (const char *);
    String substring(int from, int to);
    ~String();
};
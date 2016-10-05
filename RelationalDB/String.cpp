//
//  String.cpp
//  RelationalDB
//
//  Created by Andrii Selivanov on 10/5/16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "String.hpp"
#include <string.h>

bool String::operator ==(const String &rhs) {
    return (strcmp(this->cString, rhs.cString) == 0);
}

String::String(const char *array) {
    int length;
    for (length = 0; array[length] != '\0'; length++);
    length++;
    cString = new char[length];
    strcpy(cString, array);
}

String String::substring(int from, int to) {
    char* cSubstring = new char[to - from];
    strncpy(cSubstring + from, this->cString, to - from);
    
    return String(cSubstring);
}

String::~String() {
    delete this->cString;
}

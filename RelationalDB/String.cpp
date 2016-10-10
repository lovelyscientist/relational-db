//
//  String.cpp
//  RelationalDB
//
//  Created by Andrii Selivanov on 10/5/16.
//  Copyright © 2016 xxx. All rights reserved.
//

#include "String.hpp"
#include <string.h>
#include <iostream>

bool String::operator ==(const String &rhs) {
    return (strcmp(this->cString, rhs.cString) == 0);
}

String::String(const char *array) {
    cString = new char[this->getLength(array)];
    strcpy(cString, array);
}

String String::substring(int from, int to) {
    char* cSubstring = new char[to - from];
    strncpy(cSubstring + from, this->cString, to - from);
    
    return String(cSubstring);
}

void String::print() {
    printf("%s", this->cString);
}

int String::getLength(const char *array) {
    int length;
    for (length = 0; array[length] != '\0'; length++);
    length++;
    return length;
}

String::~String() {
    delete this->cString;
}

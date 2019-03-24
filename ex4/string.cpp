#include "string.h"
#include <iostream>


String::String() {  
    this->buffer = new char[1];  
    this->buffer[0] = '\0';  
    this->size = 0;
}

String::String(const char *str) 
{ 
    this->size = strlen(str); 
    this->buffer = new char[size+1]; 
    strcpy(buffer, str); 
}

String::String(char ch, int repetitions) {
    this->buffer = new char[repetitions + 1];
    for (unsigned i = 0; i < repetitions; i++) {
        this->buffer[i] = ch;
    }
    this->buffer[repetitions] = '\0';
    this->size = repetitions;
}

String::String(const String& old_str)
{ 
    size = old_str.size; 
    buffer = new char[size+1]; 
    strcpy(buffer, old_str.buffer); 
} 

String::~String() {
    delete[] this->buffer;
}

String& String::operator=(const String& str) {
}

// Implementation of [] operator.  
// This function must return a reference as array element can be put on left side 
char& String::operator[](int index) 
{ 
}

//
// Created by Shon on 14/03/18.
//
#define EOS '\0'
#define BUFFER_SIZE 1024
#include "cstring.h"
#include "stdexcept"

String::String() {
    length = 0;
    string = new char[1];
    string[0] = EOS;
}

String::String(const char* str){
    length = 0;
    while(str[length] != EOS) {
        length++;
    }
    string = new char[length+1];

    memcpy(string, str, length+1);
}

String::String(const String& str) {
    length = str.length;
    string = new char[length+1];
    *this = str;
}

String& String::operator=(const String &str) {
    if(length != str.length) { // no need to recreate the string if the sizes are equal
        delete[] string;
        length = str.length;
        string = new char[length+1];
    }

    memcpy(string, str.string, length+1);

    return *this;
}

String& String::operator=(const char *str){
    String toAssign(str);
    return (*this) = toAssign;
}

String::String(const char c) {
    length = 1;
    string = new char[length+1];
    string[0] = c;
    string[1] = EOS;
}

String::String(const int i) {
    char buffer[BUFFER_SIZE];
    int l;
    length = (size_t)sprintf(buffer, "%d", i);
    string = new char[length+1];
    memcpy(string, buffer, length+1);
}

String::String(const double d) {
    char buffer[BUFFER_SIZE];
    length = (size_t)sprintf(buffer, "%f", d);
    string = new char[length+1];
    memcpy(string, buffer, length+1);
}

String::String(const bool b) {
    if(b) {
        *this = String("true");
    } else {
        *this = String("false");
    }
}

bool String::operator==(const String &str) const {
    if(length == str.length && !memcmp(string, str.string, length)) {
        return true;
    }
    return false;
}

bool String::equals(const String &str) const {
    return *this == str;
}

char& String::at(size_t i) {
    if(i >= length) {
        throw std::out_of_range("String::at() : index out of range");
    }
    return string[i];
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    for(size_t i = 0; i < str.length; i++) {
        os << str.string[i];
    }
    return os;
}


size_t String::size() const{
    return length;
}

const char* String::toCharArray() const {

}



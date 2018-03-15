//
// Created by Shon on 14/03/18.
//
#define EOS '\0'
#include "cstring.h"

String::String() {
    length = 0;
    string = new char[1];
    string[0] = EOS;
}

String::String(char* str){
    length = 0;
    while(str[length] != EOS) {
        length++;
    }
    string = new char[length+1];

    memcpy(string, str, length+1);

    for (size_t i = 0; i <= length; ++i) {
        string[i] = str[i];
    }
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



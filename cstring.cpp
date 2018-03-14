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

// TODO: for the case if there is no EOS found, we can probably create a long long counter and throw an exception if it overflows
String::String(char* str){
    length = 0;
    while(str[length] != EOS) {
        length++;
    }
    string = new char[length+1];
    for (size_t i = 0; i <= length; ++i) {
        string[i] = str[i];
    }
}

size_t String::size() const{
    return length;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    for(size_t i = 0; i < str.length; i++) {
        os << str.string[i];
    }
    return os;
}
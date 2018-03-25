//
// Created by Shon on 14/03/18.
//
#define EOS '\0'
#define BUFFER_SIZE 1024
#include "cstring.h"
#include <limits>

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
    memcpy(string, str.string, length+1);
}

String::~String(){
    if(string != nullptr) {
        delete string;
    }
}

String& String::operator=(const String &str) {
    if(&str != this && length != str.length) { // no need to recreate the string if the sizes are equal
        delete[] string;
        length = str.length;
        string = new char[length+1];
    }

    memcpy(string, str.string, length+1);

    return *this;
}

String& String::assign(const char *str) {
    return (*this) = str;
}

String& String::assign(const String &str) {
    return (*this) = str;
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
        length = 4;
        string = new char[length+1];
        memcpy(string, "true", length+1);
    } else {
        length = 5;
        string = new char[length+1];
        memcpy(string, "false", length+1);
    }
}

bool operator==(const String& left, const String& right) {
    return left.length == right.length && !memcmp(left.string, right.string, left.length);
}

bool String::equals(const String &str) const {
    return *this == str;
}

char& String::at(const size_t i) {
    return string[i];
}

char& String::operator[](const size_t i) {
    if(i >= length) {
        throw std::out_of_range("index out of range");
    }
    return string[i];
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    for(size_t i = 0; i < str.length; i++) {
        os << str.string[i];
    }
    return os;
}


size_t String::size() const {
    return length;
}

const char* String::data() const {
    return string;
}

String operator+(const String& left, const String& right) {
    // we can also do this using strcat function, but this method seems to be faster because we already know
    // the lengths of the char arrays
    size_t length = left.length + right.length;
    char string[length+1];
    memcpy(string, left.string, left.length); // do not copy the EOS char here
    memcpy(string+left.length, right.string, right.length+1); // copy the EOS char here
    String res(string);
    return res;
}

String String::concat(const String &str) const {
    return *this + str;
}

String& String::operator+=(const String &str) {
    *this = *this + str;
    return *this;
}

String& String::append(const String &str) {
    return *this += str;
}

String String::subString(size_t pos, size_t len) const {
    if(pos > length) {
        throw std::out_of_range("index out of range");
    }

    // if the index of the last character of the substring is out of string's length,
    // we fit it to string's length
    if(len == std::numeric_limits<std::size_t>::max() || pos + len - 1 > length) {
        len = length - pos + 1;
    }

    char substr[len+1];
    memcpy(substr, string+pos, len);
    substr[len] = EOS;

    return String(substr);
}


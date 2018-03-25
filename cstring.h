//
// Created by Shon on 14/03/18.
//

#ifndef POO2_LABO14_STRING_H
#define POO2_LABO14_STRING_H


#include <cstddef>
#include <iostream>

class String {
private:
    char *string;
    size_t length;
public:
    String();
    String(const char* str);
    String(const String& str);
    String(const char c);
    String(const int i);
    String(const double d);
    String(const bool b);

    bool equals(const String& str) const;

    String& assign(const String& str);
    String& assign(const char* str);

    String& append(const String& str);
    String concat(const String& str) const;

    String subString(size_t pos = 0, size_t len = std::numeric_limits<std::size_t>::max()) const;

    //TODO :Demande précisions au sujet de la partie facultative
    //TODO: destructor

    size_t size() const;
    const char* data() const;
    char& at(const size_t i);

    String& operator=(const String& str);
    String& operator+=(const String& str);
    char& operator[](const size_t i);

    // these operators will not change the object so they have no need to be the member functions
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend bool operator==(const String& left, const String& right);
    friend String operator+(const String& left, const String& right);
};


#endif //POO2_LABO14_STRING_H

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
    explicit String(const char* str);
    String(const String& str);
    String(char c);
    String(int i);
    String(double d);
    String(bool b);

    bool equals(const String& str) const;

    String& assign(const String& str);
    String& assign(const char* str);

    String& append(const String& str);
    String concat(const String& str) const;

    String subString(String& str, size_t first, size_t last) const;

    void print(String& str) const;

    //TODO :Demande précisions au sujet de la partie facultative
    //TODO: need a function char* + String
    //TODO: + has to be a fucntion and not a method
    //TODO: [] operator
    //TODO: destructor
    //TODO: check if we need operator=(char*), guess no need cuz we have a corresponding constructor

    size_t size() const;
    const char* toCharArray() const;
    char& at(size_t i);

    String& operator=(const String& str);
    String& operator=(const char* str);
    bool operator==(const String& str) const;
    String& operator+=(const String& str);
    String operator+(const String& str); // gotta be a function
    friend std::ostream& operator<<(std::ostream& os, const String& str);
};


#endif //POO2_LABO14_STRING_H

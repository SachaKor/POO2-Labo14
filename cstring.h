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
    String(char* str);
    size_t size() const;
    friend std::ostream& operator<<(std::ostream& os, const String& str);
};


#endif //POO2_LABO14_STRING_H

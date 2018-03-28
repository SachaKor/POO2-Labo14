/*
 * Created by Alexandra Korukova and Samuel Mayor on 14/03/18.
 *
 * This class is an ersatz of String implementation of the STL
*/

#ifndef POO2_LABO14_STRING_H
#define POO2_LABO14_STRING_H


#include <cstddef>
#include <iostream>
#include <limits>

class String {
private:
    char *string;
    size_t length;
public:
    /*
     * @brief : Constructor of an empty String
     */
    String();

    /*
     * @brief : Constructor with a char array
     * @param : char* str -> char array
     */
    String(const char* str);

    /*
     * @brief : Constructor with a reference on a String
     * @param : String& str -> String to copy
     */
    String(const String& str);

    /*
     * @brief : Constructor with a char
     * @param : char c -> char to create String with
     */
    String(const char c);

    /*
     * @brief : Constructor with an int
     * @param : int i -> int to create String with
     */
    String(const int i);

    /*
     * @brief : Constructor with a double
     * @param : int i -> double to create String with
     */
    String(const double d);

    /*
     * @brief : Constructor with a boolean
     * @param : bool b -> boolean to create String with
     */
    String(const bool b);

    /*
     * @brief : String destructor
     */
    ~String();

    /*
     * @brief : Compare this String to the content of another
     * @param : String& str -> other String to compare with this
     * @return : Boolean wether it's equal or not
     */
    bool equals(const String& str) const;

    /*
     * @brief : Assign a String content to this String
     * @param : String& str -> String to copy content from
     * @return : Reference to this string
     */
    String& assign(const String& str);

    /*
     * @brief : Assign a char array content to this String
     * @param : String& str -> char array to copy content from
     * @return : Reference to this string
     */
    String& assign(const char* str);

    /*
     * @brief : append a String content to this String
     * @param : String& str -> String to append
     * @return : Reference to this string
     */
    String& append(const String& str);

    /*
     * @brief : Concatenate a string to this one and return result as a new one
     * @param : String& str -> String to concatenate with this string
     * @return : New concatenated string
     */
    String concat(const String& str) const;

    /*
     * @brief : Create a new string containing characters between pos and len
     * @param : size_t pos : start position of sub string
     * @param : size_t len : length of sub string
     * @return : newly created sub string
     */
    String subString(size_t pos = 0, size_t len = std::numeric_limits<std::size_t>::max()) const;

    /*
     * @brief : returns size of this string
     * @return : size of this string
     */
    size_t size() const;

    /*
     * @brief : Returns the char array of the string
     * @return : char array of the string
     */
    const char* data() const;

    /*
     * @brief : access a character in this string
     * @param : const size_t i -> index of wanted char
     * @return : reference on found char
     */
    char& at(const size_t i);

    /*
     * @brief : overrides = operator
     * @param : const String& str -> reference on string to assign to this string
     * @return : Reference on this changed string
     */
    String& operator=(const String& str);

    /*
     * @brief : overrides += operator
     * @param : const String& str -> reference on string to concatenate with this string
     * @return : Reference on this changed string
     */
    String& operator+=(const String& str);

    /*
     * @brief : overrides [] operator to access a character in this string
     * @param : const size_t i -> index of wanted char
     * @return : reference on found char
     */
    char& operator[](const size_t i);

    // these operators will not change the object so they have no need to be the member functions
    /*
     * @brief : overrides << operator to display a string
     * @param : std::ostream& os -> reference on stream in which to write
     * @param : const String& str -> reference on string to print
     * @return : Stream
     */
    friend std::ostream& operator<<(std::ostream& os, const String& str);

    /*
     * @brief : overrides == operator
     * @param : const String& left -> left string
     * @param : const String& right -> right string
     * @return : Boolean wether strings are equal or not
     */
    friend bool operator==(const String& left, const String& right);

    /*
     * @brief : overrides + operator
     * @param : const String& left -> left string
     * @param : const String& right -> right string
     * @return : new concatenated string
     */
    friend String operator+(const String& left, const String& right);
};


#endif //POO2_LABO14_STRING_H

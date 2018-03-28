/*
 * Created by Alexandra Korukova and Samuel Mayor on 14/03/18.
 *
 * Test class for the String class
*/

#include <iostream>
#include <limits>
#include "cstring.h"

using namespace std;

class Test {
public:
   void constructorsTest() {
        cout << "*** Testing contructors ***" << endl;
        cout << "Creating an empty stirng" << endl;
        String emptyString;
        cout << "\"" << emptyString << "\"" << endl;
        cout << "Creating a string from a char array" << endl;
        char charArray[11] = {'c', 'o', 'n', 'v', 'e', 'r', 't', 'e', 'd', '1', '\0'};
        String strFromCharArray1(charArray);
        cout << "\"" << strFromCharArray1 << "\"" << endl;
        cout << "Creating a string from a constant char array" << endl;
        char *string = "converted2";
        String strFromCharArray2(string);
        cout << "\"" << strFromCharArray2 << "\"" << endl;
        cout << "Creating a string from another string" << endl;
        String strFromStr(strFromCharArray1);
        cout << "\"" << strFromStr << "\"" << endl;
        cout << "Creating a string from an integer" << endl;
        String strFromInt(21285);
        cout << "\"" << strFromInt << "\"" << endl;
        cout << "Creating a string from a char" << endl;
        String strFromChar('M');
        cout << "\"" << strFromChar << "\"" << endl;
        cout << "Creating a new string from a bool" << endl;
        bool b = 0;
        String strFromBool(b);
        cout << "\"" << strFromBool << "\"" << endl;
        cout << "Creating a string from a double" << endl;
        String strFromDouble(1.2345);
        cout << "\"" << strFromDouble << "\"" << endl << endl;

    }

    void methodsTest() {
        cout << "*** Testing class methods ***" << endl;
        String one("one");
        String two("two");
        cout << "First string: \"" << one << "\", second string: \"" << two << "\"" << endl;

        // ==
        cout << endl << "-- Equality operator and method" << endl;
        cout << "one == two: " << (one == two) << endl;
        cout << "one.equals(two) : " << one.equals(two) << endl;

        // []
        cout << endl << "-- Index access" << endl;
        cout << "two[0]: '" << two[0] << "'" << endl;
        // the exception will be thrown if the index is greater than size()-1
        try {
            cout << "two[two.size()]: " << two[two.size()] << endl;
        } catch (const std::out_of_range& e) {
            cout << "out of range exception caught" << endl;
        }
        // the negative argument can cause the undefined behaviour
        cout << "two[-std::numeric_limits<std::size_t>::max()]: '"
             << two[-std::numeric_limits<std::size_t>::max()] << "'" << endl;
        cout << "one.at(1): '" << one.at(1) << "'" << endl;
        one.at(1) = 'k';
        cout << "one.at(1) = 'k', one: " << one << endl;

        // no need to surcharge the operators and methids with every type the parameter can be,
        // because the implicit conversion takes place calling the corresponding constructor
        // =
        cout << endl << "-- Assign operator and method" << endl;
        cout << "two = one, two: \"" << (two = one) << "\"" << endl;
        cout << "Assigning a char array to a string..." << endl;
        char *charArray = "i am a const char*";
        two = charArray;
        cout << "two = charArray, two: \"" << two << "\"" << endl;
        two.assign(one);
        cout << "two.assign(one), two: \"" << two << "\"" << endl;
        two.assign(charArray);
        cout << "two.assign(charArray), two: \"" << two << "\"" << endl;
        one = 212;
        cout << "one = 212, one: \"" << one << "\"" << endl;
        one = true;
        cout << "one = true, one: \"" << one << "\"" << endl;
        one = 123.456;
        cout << "one = 123.456, one: \"" << one << "\"" << endl;
        cout << "Assign a string to itself" << endl;
        cout << "one = one, one: \"" << (one = one) << "\"" << endl;

        // +
        cout << endl << "-- Concatenation" << endl;
        one = "one";
        two = "two";
        cout << "one = \"one\", two = \"two\"" << endl;
        cout << "one + ' ' + two : \"" << (one + ' ' + two) << "\"" << endl;
        String three = 1 + one;
        cout << "String three = 1 + one, three: \"" << three << "\"" << endl;
        cout << "1.23 + two: \"" << 1.23 + two << "\"" << endl;
        three = one + 1 + 2 + "abc";
        cout << "three = one + 1 + 2 + \"abc\", three: \"" << three << "\"" << endl;
        // the concat method is calling the '+' operator
        cout << "one.concat(two): \"" << one.concat(two) << "\"" << endl;
        cout << "one.concat(\"abc\").concat(1).concat(false): \""
             <<one.concat("abc").concat(1).concat(false) << "\"" << endl << endl;

        // +=
        cout << "-- Append" << endl;
        cout << "one += two, one: \"" << (one += two) << "\"" << endl;
        cout << "one.append(two), one: \"" << one.append(two) << "\"" << endl;
        cout << "one += 11, one: \"" << (one += 11) << "\"" << endl;
        cout << "one += \"abc\" + 1.23, one: \"" <<  (one += "abc" + two) << "\"" << endl;
        cout  << "two.append('a').append(2).append(true).append(\"abc\"): \""
              << two.append('a').append(2).append(true).append("abc") << "\"" << endl;
        cout << "two.size(): " << two.size() << endl << endl;

        // data()
        cout << "-- Sequence of characters representation" << endl;
        one = "one";
        cout << "one = \"one\"" << endl;
        cout << "one.data(): \"" << one.data() << "\"" << endl;
        cout << "printf(\"%s\", one.data()): ";
        printf("%s", one.data());
        cout << endl << endl;

        // subString()
        cout << "-- Substring" << endl;
        cout << "one.subString(0, 1): \""<< one.subString(2, 1) << "\"" << endl;
        // the second parameter is fit to the string's length in case the index of the last character of the substring
        // overpasses the initial string's length
        cout << "one.subString(0, 5): \"" << one.subString(0, 5) << "\"" << endl;
        // if the firs parameter equals to the string's length, the empty string is returned
        cout << "one.subString(one.size(), 1): \"" << one.subString(one.size(), 1) << "\"" << endl;
        cout << "one.subString(one.size(), one.size()): \"" << one.subString(one.size(), one.size()) << "\"" << endl;
        try {
            // but when the first parameter overpasses the string's length, the out of range exception is thrown
            cout << "one.subString(one.size() + 1, one.size()): " << one.subString(one.size() + 1, one.size()) << endl;
        } catch(const std::out_of_range& e) {
            cout << "out of range exception caught" << endl;
        }
        // both of the parameters have the default values
        cout << "one.subString(): " << one.subString() << endl;
        cout << "one.subString(2): "<< one.subString(2) << endl;
    }

};

int main() {
    Test t;
    t.constructorsTest();
    t.methodsTest();
}

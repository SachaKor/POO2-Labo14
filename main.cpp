#include <iostream>
#include "cstring.h"

using namespace std;

class ConstructorsTest {
public:
    ConstructorsTest() {
        cout << "*** Testing contructors ***" << endl;
        cout << "Creating an empty stirng" << endl;
        String emptyString;
        cout << "<" << emptyString << ">" << endl;
        cout << "Creating a string from a char arrray" << endl;
        char charArray[11] = {'c', 'o', 'n', 'v', 'e', 'r', 't', 'e', 'd', '1', '\0'};
        char *string = "converted2";
        String strFromCharArray1(charArray);
        String strFromCharArray2(string);
        cout << "<" << strFromCharArray1 << ">" << endl;
        cout << "<" << strFromCharArray2 << ">" << endl;
        cout << "Creating a string from another string" << endl;
        String strFromStr(strFromCharArray1);
        cout << "<" << strFromStr << ">" << endl;
        cout << "Creating a string from an integer" << endl;
        String strFromInt(21285);
        cout << "<" << strFromInt << ">" << endl;
        cout << "Creating a string from a char" << endl;
        String strFromChar('M');
        cout << "<" << strFromChar << ">" << endl;
        cout << "Creating a new string from a bool" << endl;
        bool b = 0;
        String strFromBool(b);
        cout << "<" << strFromBool << ">" << endl << endl;
    }

};

int main() {
    ConstructorsTest ct;
//    cout << "*** Testing functions ***" << endl;
//    String one("one");
//    String two("two");
//    cout << "First string: <" << one << ">, second string: <" << two << ">" << endl;
//    cout << "one == two: " << (one == two) << endl;
//    two = one;
//    cout << "After affecting one to two... " << endl;
//    cout << "one equals two: " << one.equals(two) << endl;
//    cout << "Checking at() function: one.at(1): " << one.at(1) << endl;
//    cout << "Modifying the second char of one..." << endl;
//    one.at(1) = 'k';
//    cout << "one: " << one << endl;
//    cout << "Assigning a char array to a string..." << endl;
//    two = charArray;
//    cout << "two = charArray, two: " << two << endl;
//    two.assign(one);
//    cout << "two.assign(one), two: " << two << endl;
//    two.assign(charArray);
//    cout << "two.assign(charArray), two: " << two << endl;
//    // no need to surcharge the '=' operator with the int parameter
//    // because we have the constructor who take an int as a parameter
//    String strFromInt1 = 23;
//    cout << strFromInt1 << endl;
}
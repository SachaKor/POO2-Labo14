#include <iostream>
#include "cstring.h"

using namespace std;

int main(){
    cout << "*** Testing contructors ***" << endl;
    cout << "Creating an empty stirng" << endl;
    String emptyString;
    cout << "<" << emptyString << ">" << endl;
    cout << "Creating a string from a char arrray" << endl;
    char charArray[10] = {'c', 'o', 'n', 'v', 'e', 'r', 't', 'e', 'd', '\0'};
    String strFromCharArray(charArray);
    cout << "<" << strFromCharArray << ">" << endl;
}
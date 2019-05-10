#include "std_lib_facilities.h"

int main()
{
    cout << "Unsafe operations: \n\ndouble to int";
    double doub = 10000000000000000;
    int int_doub = doub;
    double doub1 = int_doub;
    cout << "\ninitial double: " << doub << "\ndouble after conversion: " << doub1;
    cout << "\n\ndouble to char";
    char ch_doub = doub;
    double doub2 = ch_doub;
    cout << "\ninitial double: " << doub << "\ndouble after conversion: " << doub2;
    cout << "\n\ndouble to bool";
    bool bool_doub = doub;
    double doub3 = bool_doub;
    cout << "\ninitial double: " << doub << "\ndouble after conversion: " << doub3;
    cout << "\n\nint to char";
    int integer = 1000000;
    char char_int = integer;
    int integer1 = char_int;
    cout << "\ninitial int: " << integer << "\nint after conversion: " << integer1;
    cout << "\n\nint to bool";
    bool bool_int = integer;
    int integer2 = bool_int;
    cout << "\ninitial int: " << integer << "\nint after conversion: " << integer2;
    cout << "\n\nchar to bool";
    char character = 'a';
    bool bool_chr = character;
    char character1 = bool_chr;
    cout << "\ninitial char: " << character << "\nchar after conversion: " << character1;
    cout << "\n\n";
    return 0;

}

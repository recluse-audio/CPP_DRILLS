#include <cassert>
#include <iostream>
#include "../SOURCE/StringReverse.h"

void test_reverseString()
{
    assert(reverseString("ABC") == "CBA");
    assert(reverseString("123") == "321");
}

int main()
{
    test_reverseString();
    std::cout << "All Tests PASSED!!!";
    return 0;
}

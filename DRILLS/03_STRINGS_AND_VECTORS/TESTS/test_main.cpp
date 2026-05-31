#include <cassert>
#include <iostream>
#include "StringReverse.h"

void test_reverseString()
{
    assert(reverseString("ABC") == "CBA");
}

int main()
{
    test_reverseString();
    std::cout << "All Tests PASSED!!!"
    return 0;
}

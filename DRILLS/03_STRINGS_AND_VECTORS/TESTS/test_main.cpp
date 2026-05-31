#include <cassert>
#include <iostream>
#include "../SOURCE/StringModifier.h"

void test_reverseString()
{
    assert(reverseString("ABC") == "CBA");
    assert(reverseString("123") == "321");
}

void test_trim()
{
    assert(trim("  ABC  ") == "ABC");
}


int main()
{
    test_reverseString();
    test_trim();
    // test_split();
    // test_join();
    // test_sum();
    // test_in_place_double();
    std::cout << "All Tests PASSED!!!";
    return 0;
}

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

void test_split()
{
    std::string testString = "ABC,123,DEF";
    std::vector<std::string> stringVec = split(testString, ',');
    std::cout << "stringVec[0]: " << stringVec[0] << "\n";
    std::cout << "stringVec[1]: " << stringVec[1] << "\n";
    std::cout << "stringVec[2]: " << stringVec[2] << "\n";
    assert(stringVec[0] == "ABC");
    assert(stringVec[1] == "123");
    assert(stringVec[2] == "DEF");
}

void test_join()
{
    std::string testString = "ABC,123,DEF";
    const std::vector<std::string> stringVec = split(testString, ',');
    std::string joinedString = join(stringVec, 'z');
    std::cout << "joined string: " << joinedString << " \n";
    assert(joinedString == "ABCz123zDEF");
}

int main()
{
    test_reverseString();
    test_trim();
    test_split();
    test_join();
    std::cout << "All Tests PASSED!!!";
    return 0;
}

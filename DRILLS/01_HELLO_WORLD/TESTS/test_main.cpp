#include <cassert>
#include <iostream>
#include <sstream>

// helper test function
std::string greet()
{
    return "hello world";
}

void test_greet()
{
    assert(greet() == "hello world");
    std::cout << "test_greet passed \n";
}

int main()
{
    test_greet();
    std::cout << "all tests passed";
    return 0;
}

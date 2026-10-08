#include <cassert>
#include <iostream>
#include "../SOURCE/Logic.h"



void test_classify()
{
    assert(classify(5) == "positive");
    assert(classify(-3) == "negative");

}

void test_is_prime()
{
    assert(is_prime(2) == true);
    assert(is_prime(4) == false);
    assert(is_prime(6) == false);
    assert(is_prime(37) == true);
}

void test_to_binary()
{
    assert(to_binary(5) == "101");
    assert(to_binary(0) == "0");
    assert(to_binary(1) == "1");
    assert(to_binary(2) == "10");
    assert(to_binary(3) == "11");
    assert(to_binary(255) == "11111111");
    assert(to_binary(254) == "11111110");

}

int main()
{
    test_classify();
    test_is_prime();
    test_to_binary();
    std::cout << "all tests passed";
    return 0;
}

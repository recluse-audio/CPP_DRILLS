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

}

int main()
{
    test_classify();
    test_is_prime();
    test_to_binary();
    std::cout << "all tests passed";
    return 0;
}

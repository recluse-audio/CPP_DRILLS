#include <cassert>
#include <iostream>
#include "../SOURCE/BufferProcessor.h"

void test_swap_by_ref()
{
    int a = 5;
    int b = 6;
    swap_by_ref(a, b);
    assert(a == 6);
    assert(b == 5);
}

void test_swap_by_ptr()
{

}

void test_find()
{

}

void test_c_strlen()
{

}

void test_reverse_in_place()
{

}

int main(int argc, char* argv[])
{
    test_swap_by_ref();
    test_swap_by_ptr();
    test_find();
    test_c_strlen();
    test_reverse_in_place();

    std::cout << "All tests passed!";
    return 0;
}

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

    int a = 5;
    int b = 6;
    swap_by_ptr(&a, &b);
    assert(a == 6);
    assert(b == 5);
}

void test_find()
{
    // create array of int values we will search
    int arr[5] = {10, 20, 30, 40, 50};
    int* result = find(arr, arr + 5, 30);
    assert(result != nullptr); // we found something
    assert(*result == 30); // value at result address is 30
    assert(result - arr == 2); // pointer subtraction aka index calculation [2]-0
    //
    // Test Value not in range
    int* expectedFail = find(arr, arr + 5, 60);
    assert(expectedFail == nullptr);

    // TODO: Could use some more test cases
}

void test_c_strlen()
{
    const char* charString = "test_charString";
    int numChars = c_strlen(charString);
    assert(numChars == 15);
}

void test_reverse_in_place()
{
    int arr[5] = {10, 20, 30, 40, 50};
    reverse_in_place(arr, 5);
    assert(arr[0] == 50);
    assert(arr[1] == 40);
    assert(arr[2] == 30);
    assert(arr[3] == 20);
    assert(arr[4] == 10);
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

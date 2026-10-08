// swap_by_ref() swap_by_ptr() find() c_strlen() reverse_in_place() in SOURCE/BufferProcessor.cpp
// SOLUTION/Makefile test target - links with -fsanitize=address / reports read or write outside int array
#include <catch_amalgamated.hpp>

#include <cstddef>

#include "BufferProcessor.h"

TEST_CASE("swap_by_ref swaps two int values")
{
    int a = 5;
    int b = 6;
    swap_by_ref(a, b);
    REQUIRE(a == 6);
    REQUIRE(b == 5);
}

TEST_CASE("swap_by_ptr swaps two int values through their addresses")
{
    int a = 5;
    int b = 6;
    swap_by_ptr(&a, &b);
    REQUIRE(a == 6);
    REQUIRE(b == 5);
}

TEST_CASE("swap_by_ptr changes nothing when one pointer is nullptr")
{
    int a = 5;
    swap_by_ptr(&a, nullptr);
    swap_by_ptr(nullptr, &a);
    REQUIRE(a == 5);
}

TEST_CASE("find returns the address of the target")
{
    int samples[5] = {10, 20, 30, 40, 50};
    int* found = find(samples, samples + 5, 30);
    REQUIRE(found != nullptr);
    REQUIRE(*found == 30);
    REQUIRE(found - samples == 2);
}

TEST_CASE("find returns nullptr for a missing target and an empty range and a nullptr range")
{
    int samples[5] = {10, 20, 30, 40, 50};
    REQUIRE(find(samples, samples + 5, 60) == nullptr);
    REQUIRE(find(samples, samples, 10) == nullptr);
    REQUIRE(find(nullptr, nullptr, 10) == nullptr);
}

TEST_CASE("find stops one before the end pointer")
{
    int samples[5] = {10, 20, 30, 40, 50};
    REQUIRE(find(samples, samples + 2, 30) == nullptr);
}

TEST_CASE("c_strlen counts the characters before the terminator")
{
    REQUIRE(c_strlen("test_charString") == 15);
    REQUIRE(c_strlen("") == 0);
    REQUIRE(c_strlen(nullptr) == 0);
}

TEST_CASE("reverse_in_place reverses an odd count and an even count")
{
    int odd_samples[5] = {10, 20, 30, 40, 50};
    reverse_in_place(odd_samples, 5);
    REQUIRE(odd_samples[0] == 50);
    REQUIRE(odd_samples[2] == 30);
    REQUIRE(odd_samples[4] == 10);

    int even_samples[4] = {1, 2, 3, 4};
    reverse_in_place(even_samples, 4);
    REQUIRE(even_samples[0] == 4);
    REQUIRE(even_samples[1] == 3);
    REQUIRE(even_samples[2] == 2);
    REQUIRE(even_samples[3] == 1);
}

TEST_CASE("reverse_in_place changes nothing for a count of 0 and for nullptr")
{
    int samples[2] = {1, 2};
    reverse_in_place(samples, 0);
    reverse_in_place(nullptr, 2);
    REQUIRE(samples[0] == 1);
    REQUIRE(samples[1] == 2);
}

// sum_in_one_thread() sum_in_threads() in SOURCE/ThreadSum.cpp - called here with same std::vector<int>
// SOLUTION/Makefile test target - links with -fsanitize=thread / reports unguarded write to shared total
#include <catch_amalgamated.hpp>

#include <stdexcept>
#include <vector>

#include "ThreadSum.h"

std::vector<int> build_counting_values(int last_value)
{
    std::vector<int> values;
    for (int value = 1; value <= last_value; value++)
    {
        values.push_back(value);
    }
    return values;
}

TEST_CASE("sum_in_one_thread adds 1 to 1000")
{
    std::vector<int> values = build_counting_values(1000);
    REQUIRE(sum_in_one_thread(values) == 500500);
}

TEST_CASE("sum_in_threads equals the one thread sum for 1 and 2 and 4 threads")
{
    std::vector<int> values = build_counting_values(1000);
    long long expected = sum_in_one_thread(values);

    REQUIRE(sum_in_threads(values, 1) == expected);
    REQUIRE(sum_in_threads(values, 2) == expected);
    REQUIRE(sum_in_threads(values, 4) == expected);
}

TEST_CASE("sum_in_threads gives the remainder to the last thread")
{
    std::vector<int> values = build_counting_values(10);
    REQUIRE(sum_in_threads(values, 3) == 55);
}

TEST_CASE("sum_in_threads works with more threads than values")
{
    std::vector<int> values = build_counting_values(3);
    REQUIRE(sum_in_threads(values, 8) == 6);
}

TEST_CASE("sum_in_threads returns 0 for an empty vector")
{
    std::vector<int> values;
    REQUIRE(sum_in_threads(values, 4) == 0);
}

TEST_CASE("sum_in_threads throws std::invalid_argument for a thread count below 1")
{
    std::vector<int> values = build_counting_values(10);
    REQUIRE_THROWS_AS(sum_in_threads(values, 0), std::invalid_argument);
}

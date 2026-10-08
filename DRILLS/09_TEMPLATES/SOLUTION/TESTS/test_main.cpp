// Stack<T> find_largest<T>() in SOURCE/Stack.h - instantiated here with int / std::string
#include <catch_amalgamated.hpp>

#include <stdexcept>
#include <string>
#include <vector>

#include "Stack.h"

TEST_CASE("Stack<int> pops the newest element first")
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    REQUIRE(stack.count_elements() == 3);
    REQUIRE(stack.pop() == 3);
    REQUIRE(stack.pop() == 2);
    REQUIRE(stack.count_elements() == 1);
}

TEST_CASE("Stack<std::string> stores strings with the same code")
{
    Stack<std::string> stack;
    stack.push("first");
    stack.push("second");

    REQUIRE(stack.peek() == "second");
    REQUIRE(stack.count_elements() == 2);
    REQUIRE(stack.pop() == "second");
    REQUIRE(stack.pop() == "first");
}

TEST_CASE("pop and peek on an empty Stack throw std::out_of_range")
{
    Stack<int> stack;
    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
}

TEST_CASE("find_largest returns the largest int")
{
    std::vector<int> values;
    values.push_back(4);
    values.push_back(9);
    values.push_back(2);

    REQUIRE(find_largest(values) == 9);
}

TEST_CASE("find_largest returns the last std::string in dictionary order")
{
    std::vector<std::string> words;
    words.push_back("pear");
    words.push_back("apple");
    words.push_back("zebra");

    REQUIRE(find_largest(words) == "zebra");
}

TEST_CASE("find_largest on an empty vector throws std::invalid_argument")
{
    std::vector<int> values;
    REQUIRE_THROWS_AS(find_largest(values), std::invalid_argument);
}

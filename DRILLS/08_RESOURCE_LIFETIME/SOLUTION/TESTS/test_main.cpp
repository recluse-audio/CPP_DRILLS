// DynamicArray in SOURCE/DynamicArray.cpp - constructed / copied / moved here
// SOLUTION/Makefile test target - links with -fsanitize=address / reports leaked or twice freed new int[]
#include <catch_amalgamated.hpp>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include "DynamicArray.h"

TEST_CASE("the constructor allocates size elements that start at 0")
{
    DynamicArray array(3);
    REQUIRE(array.getSize() == 3);
    REQUIRE(array.getElement(0) == 0);
    REQUIRE(array.getElement(2) == 0);
}

TEST_CASE("addElement stores a value that getElement returns")
{
    DynamicArray array(3);
    array.addElement(1, 42);
    REQUIRE(array.getElement(1) == 42);
}

TEST_CASE("an index outside the array throws std::out_of_range")
{
    DynamicArray array(3);
    REQUIRE_THROWS_AS(array.addElement(3, 1), std::out_of_range);
    REQUIRE_THROWS_AS(array.addElement(-1, 1), std::out_of_range);
    REQUIRE_THROWS_AS(array.getElement(3), std::out_of_range);
    REQUIRE_THROWS_AS(array.getElement(-1), std::out_of_range);
}

TEST_CASE("printArray prints the elements on one line")
{
    DynamicArray array(3);
    array.addElement(0, 1);
    array.addElement(1, 2);
    array.addElement(2, 3);

    std::ostringstream captured;
    std::streambuf* original_buffer = std::cout.rdbuf(captured.rdbuf());
    array.printArray();
    std::cout.rdbuf(original_buffer);

    REQUIRE(captured.str() == "1 2 3\n");
}

TEST_CASE("the copy constructor copies every element into a second array")
{
    DynamicArray original(2);
    original.addElement(0, 7);

    DynamicArray copy(original);
    copy.addElement(0, 9);

    REQUIRE(copy.getSize() == 2);
    REQUIRE(copy.getElement(0) == 9);
    REQUIRE(original.getElement(0) == 7);
}

TEST_CASE("copy assignment replaces the elements and leaves the source unchanged")
{
    DynamicArray source(2);
    source.addElement(1, 5);
    DynamicArray target(4);

    target = source;
    target.addElement(1, 6);

    REQUIRE(target.getSize() == 2);
    REQUIRE(target.getElement(1) == 6);
    REQUIRE(source.getElement(1) == 5);
}

TEST_CASE("copy assignment from the same object keeps the elements")
{
    DynamicArray array(2);
    array.addElement(0, 3);
    DynamicArray& same_array = array;

    array = same_array;

    REQUIRE(array.getSize() == 2);
    REQUIRE(array.getElement(0) == 3);
}

TEST_CASE("the move constructor takes the elements and leaves the source with size 0")
{
    DynamicArray source(2);
    source.addElement(0, 8);

    DynamicArray target(std::move(source));

    REQUIRE(target.getSize() == 2);
    REQUIRE(target.getElement(0) == 8);
    REQUIRE(source.getSize() == 0);
}

TEST_CASE("move assignment takes the elements and leaves the source with size 0")
{
    DynamicArray source(2);
    source.addElement(1, 4);
    DynamicArray target(5);

    target = std::move(source);

    REQUIRE(target.getSize() == 2);
    REQUIRE(target.getElement(1) == 4);
    REQUIRE(source.getSize() == 0);
}

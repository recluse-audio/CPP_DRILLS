// reverse_line() calculate_line() in SOURCE/LineTools.cpp - called here with one line of text
// BUILD/string_reverse_build BUILD/string_calculator_build - run here through std::system() with echo as standard input
#include <catch_amalgamated.hpp>

#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>

#include "LineTools.h"

std::string read_first_line(const std::string& path)
{
    std::ifstream input(path);
    std::string line;
    std::getline(input, line);
    return line;
}

TEST_CASE("reverse_line reverses the characters")
{
    REQUIRE(reverse_line("hello") == "olleh");
    REQUIRE(reverse_line("a b") == "b a");
    REQUIRE(reverse_line("") == "");
}

TEST_CASE("calculate_line applies each of the four operators")
{
    REQUIRE(calculate_line("2 + 3") == 5.0);
    REQUIRE(calculate_line("10 - 4") == 6.0);
    REQUIRE(calculate_line("6 * 7") == 42.0);
    REQUIRE(calculate_line("7 / 2") == 3.5);
}

TEST_CASE("calculate_line throws std::invalid_argument for malformed input")
{
    REQUIRE_THROWS_AS(calculate_line("2 +"), std::invalid_argument);
    REQUIRE_THROWS_AS(calculate_line("two + 3"), std::invalid_argument);
    REQUIRE_THROWS_AS(calculate_line("2 ^ 3"), std::invalid_argument);
    REQUIRE_THROWS_AS(calculate_line("2 + 3 4"), std::invalid_argument);
    REQUIRE_THROWS_AS(calculate_line(""), std::invalid_argument);
}

TEST_CASE("calculate_line throws std::domain_error for division by zero")
{
    REQUIRE_THROWS_AS(calculate_line("1 / 0"), std::domain_error);
}

TEST_CASE("string_reverse_build prints the reversed line and exits 0")
{
    int status = std::system("echo 'hello' | ./BUILD/string_reverse_build > BUILD/reverse_output.txt");
    std::string printed = read_first_line("BUILD/reverse_output.txt");
    REQUIRE(status == 0);
    REQUIRE(printed == "olleh");
}

TEST_CASE("string_calculator_build prints the result and exits 0")
{
    int status = std::system("echo '7 / 2' | ./BUILD/string_calculator_build > BUILD/calculator_output.txt");
    std::string printed = read_first_line("BUILD/calculator_output.txt");
    REQUIRE(status == 0);
    REQUIRE(printed == "3.5");
}

TEST_CASE("string_calculator_build writes to standard error and exits nonzero on bad input")
{
    std::string malformed_command =
        "echo '2 +' | ./BUILD/string_calculator_build > /dev/null 2> BUILD/malformed_error.txt";
    int malformed_status = std::system(malformed_command.c_str());
    std::string malformed_error = read_first_line("BUILD/malformed_error.txt");
    REQUIRE(malformed_status != 0);
    REQUIRE(malformed_error != "");

    std::string zero_command =
        "echo '1 / 0' | ./BUILD/string_calculator_build > /dev/null 2> BUILD/zero_error.txt";
    int zero_status = std::system(zero_command.c_str());
    std::string zero_error = read_first_line("BUILD/zero_error.txt");
    REQUIRE(zero_status != 0);
    REQUIRE(zero_error != "");
}

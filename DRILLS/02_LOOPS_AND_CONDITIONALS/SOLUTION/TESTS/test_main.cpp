// write_triangle() write_fizz_buzz() write_chessboard() in SOURCE/LoopPrograms.cpp
// each called here with std::ostringstream as output argument
#include <catch_amalgamated.hpp>

#include <sstream>
#include <string>
#include <vector>

#include "LoopPrograms.h"

std::vector<std::string> split_lines(const std::string& text)
{
    std::vector<std::string> lines;
    std::istringstream input(text);
    std::string line;
    while (std::getline(input, line))
    {
        lines.push_back(line);
    }
    return lines;
}

TEST_CASE("write_triangle writes seven lines from # to #######")
{
    std::ostringstream output;
    write_triangle(output);
    std::string written = output.str();
    REQUIRE(written == "#\n##\n###\n####\n#####\n######\n#######\n");
}

TEST_CASE("write_fizz_buzz writes 100 lines with Fizz Buzz FizzBuzz")
{
    std::ostringstream output;
    write_fizz_buzz(output);
    std::string written = output.str();
    std::vector<std::string> lines = split_lines(written);
    REQUIRE(lines.size() == 100);
    REQUIRE(lines[0] == "1");
    REQUIRE(lines[2] == "Fizz");
    REQUIRE(lines[4] == "Buzz");
    REQUIRE(lines[14] == "FizzBuzz");
    REQUIRE(lines[97] == "98");
    REQUIRE(lines[99] == "Buzz");
}

TEST_CASE("write_chessboard writes size lines that alternate space and #")
{
    std::ostringstream output;
    write_chessboard(output, 8);
    std::string written = output.str();
    std::vector<std::string> lines = split_lines(written);
    REQUIRE(lines.size() == 8);
    REQUIRE(lines[0] == " # # # #");
    REQUIRE(lines[1] == "# # # # ");
    REQUIRE(lines[7] == "# # # # ");
}

TEST_CASE("write_chessboard follows the size argument")
{
    std::ostringstream output;
    write_chessboard(output, 3);
    std::string written = output.str();
    REQUIRE(written == " # \n# #\n # \n");
}

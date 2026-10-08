// write_greeting() in SOURCE/Greeting.cpp - called here with std::ostringstream as output argument
// BUILD/hello_world_build - built by make build / run here through std::system()
#include <catch_amalgamated.hpp>

#include <cstdlib>
#include <sstream>
#include <string>

#include "Greeting.h"

TEST_CASE("write_greeting writes Hello, world! and a newline")
{
    std::ostringstream output;
    write_greeting(output);
    std::string written = output.str();
    REQUIRE(written == "Hello, world!\n");
}

TEST_CASE("hello_world_build exits 0")
{
    int status = std::system("./BUILD/hello_world_build > /dev/null");
    REQUIRE(status == 0);
}

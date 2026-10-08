// check_dependencies.sh in SOLUTION/SOURCE - run here through std::system()
// make test in SOLUTION/Makefile - sets working directory to SOLUTION
#include <catch_amalgamated.hpp>

#include <cstdlib>
#include <string>

int run_check_dependencies(const std::string& repo_dir)
{
    std::string command = "bash SOURCE/check_dependencies.sh " + repo_dir + " > /dev/null 2>&1";
    int status = std::system(command.c_str());
    return status;
}

TEST_CASE("check_dependencies.sh exits 0 for this repo")
{
    int status = run_check_dependencies("../../..");
    REQUIRE(status == 0);
}

TEST_CASE("check_dependencies.sh exits nonzero for a directory with no submodules")
{
    int status = run_check_dependencies("/tmp");
    REQUIRE(status != 0);
}

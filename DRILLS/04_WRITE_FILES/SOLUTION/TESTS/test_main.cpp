// write_text_file() write_csv_file() write_json_file() in SOURCE/RecordWriter.cpp
// each called here with build_sample_records() result / path under BUILD/test_output
// BUILD/write_files_build - run here through std::system() with BUILD/program_output as argv[1]
#include <catch_amalgamated.hpp>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "RecordWriter.h"

const std::string EXPECTED_TEXT = "alice 3\nbob 5\ncarol 8\n";
const std::string EXPECTED_CSV = "name,number\nalice,3\nbob,5\ncarol,8\n";
const std::string EXPECTED_JSON =
    "[\n"
    "    {\n"
    "        \"name\": \"alice\",\n"
    "        \"number\": 3\n"
    "    },\n"
    "    {\n"
    "        \"name\": \"bob\",\n"
    "        \"number\": 5\n"
    "    },\n"
    "    {\n"
    "        \"name\": \"carol\",\n"
    "        \"number\": 8\n"
    "    }\n"
    "]";

std::string read_file(const std::string& path)
{
    std::ifstream input(path);
    std::ostringstream contents;
    contents << input.rdbuf();
    return contents.str();
}

TEST_CASE("build_sample_records returns alice 3 and bob 5 and carol 8")
{
    std::vector<Record> records = build_sample_records();
    REQUIRE(records.size() == 3);
    REQUIRE(records[0].name == "alice");
    REQUIRE(records[0].number == 3);
    REQUIRE(records[2].name == "carol");
    REQUIRE(records[2].number == 8);
}

TEST_CASE("the three write functions write the three formats")
{
    std::filesystem::create_directories("BUILD/test_output");
    std::vector<Record> records = build_sample_records();

    write_text_file(records, "BUILD/test_output/records.txt");
    write_csv_file(records, "BUILD/test_output/records.csv");
    write_json_file(records, "BUILD/test_output/records.json");

    REQUIRE(read_file("BUILD/test_output/records.txt") == EXPECTED_TEXT);
    REQUIRE(read_file("BUILD/test_output/records.csv") == EXPECTED_CSV);
    REQUIRE(read_file("BUILD/test_output/records.json") == EXPECTED_JSON);
}

TEST_CASE("write_files_build writes the three files into its argument and exits 0")
{
    std::filesystem::create_directories("BUILD/program_output");
    int status = std::system("./BUILD/write_files_build BUILD/program_output");
    REQUIRE(status == 0);
    REQUIRE(read_file("BUILD/program_output/records.txt") == EXPECTED_TEXT);
    REQUIRE(read_file("BUILD/program_output/records.csv") == EXPECTED_CSV);
    REQUIRE(read_file("BUILD/program_output/records.json") == EXPECTED_JSON);
}

TEST_CASE("write_files_build exits nonzero with no argument")
{
    int status = std::system("./BUILD/write_files_build 2> /dev/null");
    REQUIRE(status != 0);
}

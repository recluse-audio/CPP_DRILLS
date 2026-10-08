// parse_text_file() parse_csv_file() parse_json_file() in SOURCE/RecordParser.cpp
// each called here with path of file that write_fixture_directory() wrote under BUILD
// BUILD/parse_files_build - run here through std::system() with fixture directory as argv[1]
#include <catch_amalgamated.hpp>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "RecordParser.h"

const std::string TEXT_FIXTURE = "alice 3\nbob 5\ncarol 8\n";
const std::string CSV_FIXTURE = "name,number\nalice,3\nbob,5\ncarol,8\n";
const std::string DIFFERING_CSV_FIXTURE = "name,number\nalice,3\nbob,6\ncarol,8\n";
const std::string JSON_FIXTURE =
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

void write_file(const std::string& path, const std::string& text)
{
    std::ofstream output(path);
    output << text;
}

void write_fixture_directory(const std::string& directory, const std::string& csv_text)
{
    std::filesystem::create_directories(directory);
    std::string text_path = directory + "/records.txt";
    std::string csv_path = directory + "/records.csv";
    std::string json_path = directory + "/records.json";
    write_file(text_path, TEXT_FIXTURE);
    write_file(csv_path, csv_text);
    write_file(json_path, JSON_FIXTURE);
}

std::string read_first_line(const std::string& path)
{
    std::ifstream input(path);
    std::string line;
    std::getline(input, line);
    return line;
}

void require_sample_records(const std::vector<Record>& records)
{
    REQUIRE(records.size() == 3);
    REQUIRE(records[0].name == "alice");
    REQUIRE(records[0].number == 3);
    REQUIRE(records[1].name == "bob");
    REQUIRE(records[1].number == 5);
    REQUIRE(records[2].name == "carol");
    REQUIRE(records[2].number == 8);
}

TEST_CASE("the three parse functions build the same three records")
{
    write_fixture_directory("BUILD/matching", CSV_FIXTURE);

    std::vector<Record> text_records = parse_text_file("BUILD/matching/records.txt");
    std::vector<Record> csv_records = parse_csv_file("BUILD/matching/records.csv");
    std::vector<Record> json_records = parse_json_file("BUILD/matching/records.json");

    require_sample_records(text_records);
    require_sample_records(csv_records);
    require_sample_records(json_records);
}

TEST_CASE("compare_records reports a differing number and a differing size")
{
    write_fixture_directory("BUILD/matching", CSV_FIXTURE);
    write_fixture_directory("BUILD/differing", DIFFERING_CSV_FIXTURE);

    std::vector<Record> text_records = parse_text_file("BUILD/matching/records.txt");
    std::vector<Record> csv_records = parse_csv_file("BUILD/matching/records.csv");
    std::vector<Record> differing_records = parse_csv_file("BUILD/differing/records.csv");
    std::vector<Record> empty_records;

    REQUIRE(compare_records(text_records, csv_records) == true);
    REQUIRE(compare_records(text_records, differing_records) == false);
    REQUIRE(compare_records(text_records, empty_records) == false);
}

TEST_CASE("write_records writes file name then name then number")
{
    std::vector<Record> records;
    Record alice{"alice", 3};
    records.push_back(alice);
    std::ostringstream output;

    write_records(output, "records.txt", records);

    REQUIRE(output.str() == "records.txt alice 3\n");
}

TEST_CASE("parse_files_build prints nine lines and exits 0 for matching files")
{
    write_fixture_directory("BUILD/matching", CSV_FIXTURE);
    int status = std::system("./BUILD/parse_files_build BUILD/matching > BUILD/matching_output.txt");
    std::string first_line = read_first_line("BUILD/matching_output.txt");
    REQUIRE(status == 0);
    REQUIRE(first_line == "records.txt alice 3");
}

TEST_CASE("parse_files_build prints error: to standard error and exits nonzero for differing files")
{
    write_fixture_directory("BUILD/differing", DIFFERING_CSV_FIXTURE);
    std::string command = "./BUILD/parse_files_build BUILD/differing > /dev/null 2> BUILD/differing_error.txt";
    int status = std::system(command.c_str());
    std::string error_line = read_first_line("BUILD/differing_error.txt");
    REQUIRE(status != 0);
    REQUIRE(error_line.rfind("error: ", 0) == 0);
}

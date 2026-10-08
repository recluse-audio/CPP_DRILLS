// calculate_sine_table() write_table_csv() Wavetable in SOURCE/Wavetable.cpp
// Wavetable constructed here with path of .csv that write_table_csv() wrote under BUILD
// WavetableCallback in SOURCE/WavetableCallback.cpp - calls same read_next_samples() per audio block
#include <catch_amalgamated.hpp>

#include <cmath>
#include <fstream>
#include <string>
#include <vector>

#include "Wavetable.h"

bool check_close(double first, double second)
{
    double difference = std::fabs(first - second);
    return difference < 1e-9;
}

std::string read_first_line(const std::string& path)
{
    std::ifstream input(path);
    std::string line;
    std::getline(input, line);
    return line;
}

TEST_CASE("calculate_sine_table returns one sine cycle")
{
    std::vector<double> table = calculate_sine_table(4);
    REQUIRE(table.size() == 4);
    REQUIRE(check_close(table[0], 0.0));
    REQUIRE(check_close(table[1], 1.0));
    REQUIRE(check_close(table[2], 0.0));
    REQUIRE(check_close(table[3], -1.0));
}

TEST_CASE("write_table_csv writes the header row and Wavetable parses every sample back")
{
    std::vector<double> table = calculate_sine_table(512);
    write_table_csv(table, "BUILD/test_table.csv");

    std::string header = read_first_line("BUILD/test_table.csv");
    REQUIRE(header == "index,sample");

    Wavetable wavetable("BUILD/test_table.csv");
    const std::vector<double>& samples = wavetable.get_samples();
    REQUIRE(samples.size() == 512);
    REQUIRE(samples == table);
}

TEST_CASE("read_next_samples interpolates between samples and wraps to sample 0")
{
    std::vector<double> table = calculate_sine_table(4);
    write_table_csv(table, "BUILD/small_table.csv");
    Wavetable wavetable("BUILD/small_table.csv");

    std::vector<double> samples = wavetable.read_next_samples(1.0, 8.0, 8);

    REQUIRE(samples.size() == 8);
    REQUIRE(check_close(samples[0], 0.0));
    REQUIRE(check_close(samples[1], 0.5));
    REQUIRE(check_close(samples[2], 1.0));
    REQUIRE(check_close(samples[3], 0.5));
    REQUIRE(check_close(samples[6], -1.0));
    REQUIRE(check_close(samples[7], -0.5));
}

TEST_CASE("read_next_samples keeps the phase for the next call")
{
    std::vector<double> table = calculate_sine_table(4);
    write_table_csv(table, "BUILD/small_table.csv");
    Wavetable wavetable("BUILD/small_table.csv");

    std::vector<double> first_block = wavetable.read_next_samples(1.0, 8.0, 3);
    std::vector<double> second_block = wavetable.read_next_samples(1.0, 8.0, 2);

    REQUIRE(check_close(first_block[2], 1.0));
    REQUIRE(check_close(second_block[0], 0.5));
    REQUIRE(check_close(second_block[1], 0.0));
}

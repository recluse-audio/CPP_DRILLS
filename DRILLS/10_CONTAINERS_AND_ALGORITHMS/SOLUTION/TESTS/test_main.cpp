// count_words() sort_words_by_count() check_word_listed() in SOURCE/WordCounter.cpp
// BUILD/word_counter_build - run here through std::system() with echo as standard input
#include <catch_amalgamated.hpp>

#include <cstdlib>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "WordCounter.h"

std::string read_first_line(const std::string& path)
{
    std::ifstream input(path);
    std::string line;
    std::getline(input, line);
    return line;
}

TEST_CASE("count_words counts each word of the text")
{
    std::map<std::string, int> counts = count_words("the cat and the hat and the bat");
    REQUIRE(counts.size() == 5);
    REQUIRE(counts["the"] == 3);
    REQUIRE(counts["and"] == 2);
    REQUIRE(counts["cat"] == 1);
}

TEST_CASE("count_words returns an empty map for text with no word")
{
    std::map<std::string, int> counts = count_words("   ");
    REQUIRE(counts.empty());
}

TEST_CASE("sort_words_by_count puts the highest count first and equal counts in dictionary order")
{
    std::map<std::string, int> counts = count_words("the cat and the hat and the bat");
    std::vector<WordCount> sorted = sort_words_by_count(counts);

    REQUIRE(sorted.size() == 5);
    REQUIRE(sorted[0].word == "the");
    REQUIRE(sorted[0].count == 3);
    REQUIRE(sorted[1].word == "and");
    REQUIRE(sorted[2].word == "bat");
    REQUIRE(sorted[3].word == "cat");
    REQUIRE(sorted[4].word == "hat");
}

TEST_CASE("check_word_listed reports a listed word and a missing word")
{
    std::vector<std::string> words;
    words.push_back("cat");
    words.push_back("hat");

    REQUIRE(check_word_listed(words, "hat") == true);
    REQUIRE(check_word_listed(words, "bat") == false);
}

TEST_CASE("word_counter_build prints the count then the word and exits 0")
{
    std::string command = "echo 'b a b' | ./BUILD/word_counter_build > BUILD/program_output.txt";
    int status = std::system(command.c_str());
    std::string first_line = read_first_line("BUILD/program_output.txt");
    REQUIRE(status == 0);
    REQUIRE(first_line == "2 b");
}

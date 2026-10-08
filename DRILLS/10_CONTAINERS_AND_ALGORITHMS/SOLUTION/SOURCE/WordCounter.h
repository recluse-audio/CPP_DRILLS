#pragma once

#include <map>
#include <string>
#include <vector>

struct WordCount
{
    std::string word;
    int count;
};

std::map<std::string, int> count_words(const std::string& text);
bool compare_word_counts(const WordCount& first, const WordCount& second);
std::vector<WordCount> sort_words_by_count(const std::map<std::string, int>& counts);
bool check_word_listed(const std::vector<std::string>& words, const std::string& word);

#include "WordCounter.h"

#include <algorithm>
#include <sstream>

std::map<std::string, int> count_words(const std::string& text)
{
    std::map<std::string, int> counts;
    std::istringstream input(text);
    std::string word;
    while (input >> word)
    {
        counts[word]++;
    }
    return counts;
}

bool compare_word_counts(const WordCount& first, const WordCount& second)
{
    if (first.count != second.count)
    {
        return first.count > second.count;
    }
    return first.word < second.word;
}

std::vector<WordCount> sort_words_by_count(const std::map<std::string, int>& counts)
{
    std::vector<WordCount> sorted;
    for (const std::pair<const std::string, int>& entry : counts)
    {
        WordCount word_count{entry.first, entry.second};
        sorted.push_back(word_count);
    }

    std::vector<WordCount>::iterator first = sorted.begin();
    std::vector<WordCount>::iterator last = sorted.end();
    std::sort(first, last, compare_word_counts);
    return sorted;
}

bool check_word_listed(const std::vector<std::string>& words, const std::string& word)
{
    std::vector<std::string>::const_iterator first = words.begin();
    std::vector<std::string>::const_iterator last = words.end();
    std::vector<std::string>::const_iterator found = std::find(first, last, word);
    return found != last;
}

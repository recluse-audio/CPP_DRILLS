#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "WordCounter.h"

int main()
{
    std::ostringstream buffer;
    buffer << std::cin.rdbuf();
    std::string text = buffer.str();

    std::map<std::string, int> counts = count_words(text);
    std::vector<WordCount> sorted = sort_words_by_count(counts);

    for (const WordCount& word_count : sorted)
    {
        std::cout << word_count.count << ' ' << word_count.word << '\n';
    }
    return 0;
}

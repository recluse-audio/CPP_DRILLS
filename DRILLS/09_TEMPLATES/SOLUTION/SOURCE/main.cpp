#include <iostream>
#include <string>

#include "Stack.h"

int main()
{
    Stack<int> numbers;
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    while (numbers.count_elements() > 0)
    {
        int number = numbers.pop();
        std::cout << number << '\n';
    }

    Stack<std::string> words;
    words.push("first");
    words.push("second");
    words.push("third");
    while (words.count_elements() > 0)
    {
        std::string word = words.pop();
        std::cout << word << '\n';
    }
    return 0;
}

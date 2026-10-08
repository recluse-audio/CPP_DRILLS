#include <iostream>
#include <string>

#include "LineTools.h"

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::string reversed = reverse_line(line);
    std::cout << reversed << '\n';
    return 0;
}

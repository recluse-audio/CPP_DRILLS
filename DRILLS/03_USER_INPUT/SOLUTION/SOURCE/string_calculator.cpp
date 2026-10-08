#include <exception>
#include <iostream>
#include <string>

#include "LineTools.h"

int main()
{
    std::string line;
    std::getline(std::cin, line);
    try
    {
        double result = calculate_line(line);
        std::cout << result << '\n';
    }
    catch (const std::exception& error)
    {
        std::cerr << "error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}

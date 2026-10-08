#include "LineTools.h"

#include <sstream>
#include <stdexcept>

std::string reverse_line(const std::string& line)
{
    std::string reversed;
    int last_index = static_cast<int>(line.size()) - 1;
    for (int index = last_index; index >= 0; index--)
    {
        reversed.push_back(line[index]);
    }
    return reversed;
}

double calculate_line(const std::string& line)
{
    std::istringstream input(line);
    double left = 0.0;
    char operation = ' ';
    double right = 0.0;

    input >> left >> operation >> right;
    if (input.fail())
    {
        throw std::invalid_argument("expected <number> <operator> <number>");
    }

    std::string extra_token;
    input >> extra_token;
    if (!extra_token.empty())
    {
        throw std::invalid_argument("expected nothing after the second number");
    }

    if (operation == '+')
    {
        return left + right;
    }
    if (operation == '-')
    {
        return left - right;
    }
    if (operation == '*')
    {
        return left * right;
    }
    if (operation == '/')
    {
        if (right == 0.0)
        {
            throw std::domain_error("division by zero");
        }
        return left / right;
    }
    throw std::invalid_argument("expected one of + - * /");
}

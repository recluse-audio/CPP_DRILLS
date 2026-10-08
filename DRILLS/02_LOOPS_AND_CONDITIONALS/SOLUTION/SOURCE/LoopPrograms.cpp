#include "LoopPrograms.h"

void write_triangle(std::ostream& output)
{
    for (int line_number = 1; line_number <= 7; line_number++)
    {
        for (int column = 0; column < line_number; column++)
        {
            output << '#';
        }
        output << '\n';
    }
}

void write_fizz_buzz(std::ostream& output)
{
    for (int number = 1; number <= 100; number++)
    {
        if (number % 15 == 0)
        {
            output << "FizzBuzz";
        }
        else if (number % 3 == 0)
        {
            output << "Fizz";
        }
        else if (number % 5 == 0)
        {
            output << "Buzz";
        }
        else
        {
            output << number;
        }
        output << '\n';
    }
}

void write_chessboard(std::ostream& output, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            if ((row + column) % 2 == 0)
            {
                output << ' ';
            }
            else
            {
                output << '#';
            }
        }
        output << '\n';
    }
}

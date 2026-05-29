#include "Logic.h"

std::string classify(int n)
{
    if(n > 0)
        return "positive";
    if(n < 0)
        return "negative";
    return "zero";
}

bool is_prime(int n)
{
    if(n < 2)
        return false;
    for(int i = 2; i * i < n; ++i)
    {
        if(n % i == 0)
            return false;
    }
}

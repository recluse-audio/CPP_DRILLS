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
    // using this i*i method for efficiency
    // We are looking for numbers that are divisible by only
    // 1 and themselves. Checking all numbers below n would
    // result in checking the same divisors twice (4x9) then (9x4)
    for(int i = 2; i * i <= n; ++i)
    {
        // hitting this means it is divisible by something else
        // and leaves no remainder.
        if(n % i == 0)
            return false;
    }
    return true;
}

std::string to_binary(unsigned int n)
{
    if(n==0)
        return "0";
    std::string result;
    while(n > 0)
    {
        result = (char)('0' + (n % 2)) + result;
        n /= 2;
    }
    return result;
}

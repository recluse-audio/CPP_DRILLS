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
    // 0 returns literally "0"
    if(n==0)
        return "0";

    std::string result;
    while(n > 0)
    {
        // if modulo around 2 is 0, it is even number at this digit at needs a 1
        char bit = (n % 2 == 0) ? '0' : '1';
        // needs to be 'bit + result' for correct ordering
        // A -> BA -> CBA -> DCBA
        result = bit + result;
        // divide by two, shift digits to right
        n /= 2;
    }
    return result;
}

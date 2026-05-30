#include <iostream>
#include "string.h"
#include "Logic.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "usage " << argv[0] << " <number>\n";
        return 1;
    }
    int n = std::stoi(argv[1]);

    std::cout << n << " is " << classify[n] << " <number>\n";
    std::cout << "prime: " << (is_prime(n) ? "yes" : "no") << "\n";
    std::cout << "binary: " << to_binary(n) << "\n";


    return 0;
}

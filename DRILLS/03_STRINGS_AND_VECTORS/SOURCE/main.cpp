#include <iostream>
#include "StringReverse.h"

int main(int argc, char* argv)
{
    if(argc != 2)
    {
        std::cerr << "usage" << argv[0] << " <string>\n";
        return 1;
    }

    std::string originalString(argv[0]); // use this later to print original
    std::string reversedString = reverseString(argv[0]);

    std::cout << "original string " << originalString << "\n";
    std::cout << "reversed string " << reversedString << "\n";

    return 0;

}

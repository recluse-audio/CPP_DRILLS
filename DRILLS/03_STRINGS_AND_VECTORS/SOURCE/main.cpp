#include <iostream>
#include "StringReverse.h"

int main(int argc, char* argv [])
{
    // expecting 2 args, program name and string, not more or less
    if(argc != 2)
    {
        std::cerr << "usage" << argv[0] << " <string>\n";
        return 1;
    }

    std::string originalString(argv[1]); // use this later to print original
    std::string reversedString = reverseString(originalString);

    std::cout << "original string " << originalString << "\n";
    std::cout << "reversed string " << reversedString << "\n";

    return 0;

}

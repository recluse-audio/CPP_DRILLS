#include <iostream>
#include "StringModifier.h"

int main(int argc, char* argv [])
{
    // expecting 2 args, program name and string, not more or less
    if(argc != 2)
    {
        std::cerr << "usage" << argv[0] << " <string>\n";
        return 1;
    }

    // ORIGINAL
    std::string originalString(argv[1]); // use this later to print original
    std::cout << "original string " << originalString << "\n";

    // Remove whitespace
    std::string trimmedString = trim(originalString);
    std::cout << "trimmed string: " << trimmedString << "\n";

    std::vector<std::string> splitVector = split(originalString);
    std::cout << "num strings after split: " << splitVector.size();



    // Just for fun
    //
    std::string reversedString = reverseString(originalString);
    std::cout << "reversed string " << reversedString << "\n";

    return 0;

}

#include <iostream>
#include "StringModifier.h"

int main(int argc, char* argv [])
{
    // expecting 2 args, program name and string, not more or less
    if(argc != 4)
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

    char separatorChar = argv[2][0];
    std::vector<std::string> splitVector = split(trimmedString, separatorChar);
    std::cout << "num strings after split: " << splitVector.size();

    char newSeparatorChar = argv[3][0]; // replaces the previous one
    std::string concatString = join(splitVector, newSeparatorChar);
    std::cout << "New string after concatenation: " << concatString << " \n";

    // Just for fun
    //
    std::string reversedString = reverseString(originalString);
    std::cout << "reversed string " << reversedString << "\n";

    return 0;

}

#include "StringReverse.h"


std::string reverseString(std::string inputString)
{
    std::string outputString = "";
    int numChar = inputString.size() - 1;

    while(numChar >= 0)
    {
        // char taken from inputString starting at back
        char inputChar = inputString[numChar];
        outputString = outputString + inputChar;
        numChar--;

    }

    return outputString;
}

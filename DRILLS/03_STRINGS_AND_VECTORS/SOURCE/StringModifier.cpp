#include "StringModifier.h"


std::string reverseString(const std::string& inputString)
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

std::string trim(const std::string& inputString)
{
    std::string outputString = "";
    int numChar = inputString.size();

    for(int i = 0; i < numChar; i++)
    {
        char inputChar = inputString[i];
        if(inputChar == ' ') // REMEMBER single quotes here for char comparison``
            continue;


        outputString = outputString + inputChar;

    }
    return outputString;
}

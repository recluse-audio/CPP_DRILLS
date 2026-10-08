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

std::vector<std::string> split(const std::string& inputString, char separator)
{
    std::vector<std::string> stringVec;

    // write to this until the separator, then add copy to string vec and clear stringVec
    std::string activeString = "";

    int numCharacters = (int)inputString.size();

    // Loop through all characters in string
    // add them to activeString until separator is hit
    // when separator is hit make copy of activeString,
    // add to stringVec, clear activeString
    for(int i = 0; i < numCharacters; ++i)
    {
        char currentCharacter = inputString[i];

        // we've triggered the separation with separator
        if(currentCharacter == separator)
        {
            // only push back if not empty
            if(activeString != "")
            {
                // push_back handles copy
                stringVec.push_back(activeString);
                activeString.clear();
            }
        }
        else
        {
            activeString = activeString + currentCharacter;

            // special case detection for last letter
            if(i == numCharacters - 1)
                stringVec.push_back(activeString);
        }
    }

    return stringVec;
}

std::string join(const std::vector<std::string>& stringVec, char newSeparatorChar)
{
    int numStrings = (int)stringVec.size();

    std::string finalString = "";

    for(int i = 0; i <= numStrings - 1; ++i)
    {
        std::string activeString = stringVec[i];

        // detect NOT final, add space and appropriate separator char from arg above
        if(i != numStrings - 1)
        {
            activeString = activeString + newSeparatorChar;
        }

        finalString = finalString + activeString;
    }
    return finalString;
}

#include <string>
#include <vector>

// Reverse given string
std::string reverseString(const std::string& inputString);

// Returns a new string after removing leading and trailing whitespace
std::string trim(const std::string& inputString);

// splits at 'separator'
std::vector<std::string> split(const std::string& inputString, char separator);

// joins at separator
std::string join(const std::vector<std::string>& stringVec, char newSeparatorChar);

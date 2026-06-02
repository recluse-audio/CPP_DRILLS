#include "BufferProcessor.h"

void swap_by_ref(int& a, int& b)
{
    int tempInt = b;
    b = a;
    a = tempInt;
}

void swap_by_ptr(int* a, int* b)
{
    int tempInt = *b;
    *b = *a;
    *a = tempInt;
}

int* find(int* begin, int* end, int target)
{
    // bail out right away if you do any funny business
    if(end - begin < 0)
        return nullptr;

    std::size_t n = end - begin;
    std::size_t n_count = 0; // use this to increment up to n

    while(n_count <= n)
    {
        // get a pointer to
        int* currentValue = begin + n_count;
        if(*currentValue == target)
            return currentValue;

       n_count++;
    }

    return nullptr;
}


std::size_t c_strlen(const char* charString)
{
    std::size_t charCount = 0;

    bool isFinished = false;
    while(!isFinished)
    {
        char currentChar = charString[charCount];
        if(currentChar == '\0')
        {
            isFinished = true;
            break;
        }
        charCount++;
    }

    return charCount;
}

void reverse_in_place(int* arr, std::size_t n)
{

}

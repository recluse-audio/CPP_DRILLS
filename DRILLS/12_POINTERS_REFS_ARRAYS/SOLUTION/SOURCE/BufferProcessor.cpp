#include "BufferProcessor.h"

void swap_by_ref(int& a, int& b)
{
    int saved = a;
    a = b;
    b = saved;
}

void swap_by_ptr(int* a, int* b)
{
    if (a == nullptr || b == nullptr)
    {
        return;
    }
    int saved = *a;
    *a = *b;
    *b = saved;
}

int* find(int* begin, int* end, int target)
{
    if (begin == nullptr || end == nullptr)
    {
        return nullptr;
    }
    for (int* current = begin; current != end; current++)
    {
        if (*current == target)
        {
            return current;
        }
    }
    return nullptr;
}

std::size_t c_strlen(const char* s)
{
    if (s == nullptr)
    {
        return 0;
    }
    std::size_t length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}

void reverse_in_place(int* arr, std::size_t n)
{
    if (arr == nullptr || n == 0)
    {
        return;
    }
    int* left = arr;
    int* right = arr + n - 1;
    while (left < right)
    {
        swap_by_ptr(left, right);
        left++;
        right--;
    }
}

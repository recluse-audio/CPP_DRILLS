#include <cstddef>
#include <iostream>

#include "BufferProcessor.h"

int main()
{
    int samples[5] = {10, 20, 30, 40, 50};
    std::size_t sample_count = 5;

    reverse_in_place(samples, sample_count);
    for (std::size_t index = 0; index < sample_count; index++)
    {
        std::cout << samples[index] << '\n';
    }

    int* samples_end = samples + sample_count;
    int* found = find(samples, samples_end, 30);
    if (found != nullptr)
    {
        std::ptrdiff_t found_index = found - samples;
        std::cout << "30 is at index " << found_index << '\n';
    }
    return 0;
}

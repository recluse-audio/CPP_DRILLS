#include <iostream>
#include <vector>

#include "ThreadSum.h"

int main()
{
    std::vector<int> values;
    for (int value = 1; value <= 1000000; value++)
    {
        values.push_back(value);
    }

    long long one_thread_total = sum_in_one_thread(values);
    long long four_thread_total = sum_in_threads(values, 4);

    std::cout << "one thread: " << one_thread_total << '\n';
    std::cout << "four threads: " << four_thread_total << '\n';
    return 0;
}

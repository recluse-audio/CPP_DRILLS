#include "ThreadSum.h"

#include <functional>
#include <stdexcept>
#include <thread>

long long sum_in_one_thread(const std::vector<int>& values)
{
    long long total = 0;
    for (int value : values)
    {
        total = total + value;
    }
    return total;
}

void add_range_to_total(const std::vector<int>& values,
                        std::size_t begin,
                        std::size_t end,
                        long long& total,
                        std::mutex& total_mutex)
{
    long long local_sum = 0;
    for (std::size_t index = begin; index < end; index++)
    {
        local_sum = local_sum + values[index];
    }

    std::lock_guard<std::mutex> lock(total_mutex);
    total = total + local_sum;
}

long long sum_in_threads(const std::vector<int>& values, int thread_count)
{
    if (thread_count < 1)
    {
        throw std::invalid_argument("thread_count is below 1");
    }

    long long total = 0;
    std::mutex total_mutex;
    std::vector<std::thread> threads;

    std::size_t range_count = static_cast<std::size_t>(thread_count);
    std::size_t range_size = values.size() / range_count;

    // std::thread copies arguments - references need std::ref() / std::cref()
    std::reference_wrapper<const std::vector<int>> values_reference = std::cref(values);
    std::reference_wrapper<long long> total_reference = std::ref(total);
    std::reference_wrapper<std::mutex> mutex_reference = std::ref(total_mutex);

    for (std::size_t range_index = 0; range_index < range_count; range_index++)
    {
        std::size_t begin = range_index * range_size;
        std::size_t end = begin + range_size;
        if (range_index == range_count - 1)
        {
            end = values.size();
        }
        threads.emplace_back(add_range_to_total, values_reference, begin, end, total_reference, mutex_reference);
    }

    for (std::thread& worker : threads)
    {
        worker.join();
    }
    return total;
}

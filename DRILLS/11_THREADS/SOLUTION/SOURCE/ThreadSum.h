#pragma once

#include <cstddef>
#include <mutex>
#include <vector>

long long sum_in_one_thread(const std::vector<int>& values);
void add_range_to_total(const std::vector<int>& values,
                        std::size_t begin,
                        std::size_t end,
                        long long& total,
                        std::mutex& total_mutex);
long long sum_in_threads(const std::vector<int>& values, int thread_count);

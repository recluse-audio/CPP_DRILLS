#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

// main.cpp instantiates Stack<int> / Stack<std::string>
// member functions defined here in header - compiler needs each body where T is named
template<typename T>
class Stack
{
public:
    void push(const T& value)
    {
        elements.push_back(value);
    }

    T pop()
    {
        if (elements.empty())
        {
            throw std::out_of_range("pop on an empty Stack");
        }
        T newest = elements.back();
        elements.pop_back();
        return newest;
    }

    const T& peek() const
    {
        if (elements.empty())
        {
            throw std::out_of_range("peek on an empty Stack");
        }
        return elements.back();
    }

    std::size_t count_elements() const
    {
        return elements.size();
    }

private:
    std::vector<T> elements;
};

template<typename T>
T find_largest(const std::vector<T>& values)
{
    if (values.empty())
    {
        throw std::invalid_argument("find_largest on an empty vector");
    }
    T largest = values[0];
    for (std::size_t index = 1; index < values.size(); index++)
    {
        if (largest < values[index])
        {
            largest = values[index];
        }
    }
    return largest;
}

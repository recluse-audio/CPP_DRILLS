#include "DynamicArray.h"

#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray(int size)
{
    this->size = size;
    elements = new int[size]();
}

DynamicArray::~DynamicArray()
{
    delete[] elements;
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
    size = other.size;
    elements = new int[size]();
    for (int index = 0; index < size; index++)
    {
        elements[index] = other.elements[index];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this == &other)
    {
        return *this;
    }

    int* new_elements = new int[other.size]();
    for (int index = 0; index < other.size; index++)
    {
        new_elements[index] = other.elements[index];
    }

    delete[] elements;
    elements = new_elements;
    size = other.size;
    return *this;
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept
{
    elements = other.elements;
    size = other.size;
    other.elements = nullptr;
    other.size = 0;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] elements;
    elements = other.elements;
    size = other.size;
    other.elements = nullptr;
    other.size = 0;
    return *this;
}

void DynamicArray::addElement(int index, int value)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("addElement index is outside the array");
    }
    elements[index] = value;
}

void DynamicArray::printArray() const
{
    for (int index = 0; index < size; index++)
    {
        if (index > 0)
        {
            std::cout << ' ';
        }
        std::cout << elements[index];
    }
    std::cout << '\n';
}

int DynamicArray::getElement(int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("getElement index is outside the array");
    }
    return elements[index];
}

int DynamicArray::getSize() const
{
    return size;
}

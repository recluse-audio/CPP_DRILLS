#pragma once

// elements field - pointer from new int[size]() in constructor / freed by delete[] in ~DynamicArray()
// copy operations allocate second array / move operations take pointer and set source to nullptr
class DynamicArray
{
public:
    explicit DynamicArray(int size);
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    void addElement(int index, int value);
    void printArray() const;
    int getElement(int index) const;
    int getSize() const;

private:
    int* elements;
    int size;
};

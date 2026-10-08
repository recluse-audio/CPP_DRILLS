#include <utility>

#include "DynamicArray.h"

int main()
{
    DynamicArray original(3);
    original.addElement(0, 10);
    original.addElement(1, 20);
    original.addElement(2, 30);
    original.printArray();

    DynamicArray copy(original);
    copy.addElement(0, 99);
    copy.printArray();
    original.printArray();

    DynamicArray moved(std::move(copy));
    moved.printArray();
    return 0;
}

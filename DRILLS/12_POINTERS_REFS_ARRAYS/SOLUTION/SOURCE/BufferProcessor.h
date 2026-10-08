#pragma once

#include <cstddef>

void swap_by_ref(int& a, int& b);
void swap_by_ptr(int* a, int* b);
int* find(int* begin, int* end, int target);
std::size_t c_strlen(const char* s);
void reverse_in_place(int* arr, std::size_t n);

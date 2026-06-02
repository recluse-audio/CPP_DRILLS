/**
 * Created By: Ryan Devens on 2026-06-02
 *
 */
#include <cstddef>
// functions for processing arrays of values similar to how you would an audio-buffer

// 1) given two int arrays, swap their values
void swap_by_ref(int& a, int& b);

// 2) same as above but with ptr
void swap_by_ptr(int* a, int* b);

// 3) begin/end int* addresses of elements, not indices
// for ranges like 3-5 in an array intArray you'd say:
// `begin = intArray+3; `
// eng = intArray=5`
int* find(int* begin, int* end, int target);

// 4)
std::size_t c_strlen(const char* s);

// 5)
void reverse_in_place(int* arr, std::size_t n);

#include "heap_sort.hpp"
#include <algorithm>

void heap_sort(std::vector<int>& nums) {
    std::make_heap(nums.begin(), nums.end());
    int sorted = 0;
    while (sorted < nums.size()-1) {
        std::pop_heap(nums.begin(), nums.end()-sorted);
        ++sorted;
    }
}
#include "merge_sort.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector nums = {4, 1, 23, 5, 6, 2, 3};
    merge_sort(nums);
    for (auto num : nums) {
        std::cout << std::to_string(num) << " ";
    }
    std::cout << std::endl;
    return 0;
}
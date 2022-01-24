#include <vector>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include <sstream>

#include "merge_sort.hpp"
#include "heap_sort.hpp"
#include "quick_sort.hpp"

int main() {
    std::cerr << "Enter a whitespace separated list of intergers, "
              << "and I will sort it for you:\n";
    std::string nums_s;
    std::getline(std::cin, nums_s);
    std::istringstream nums_ss(nums_s);
    std::vector<int> nums;
    int num;
    while (nums_ss >> num) nums.push_back(num);

    std::unordered_map<int, std::function<void(std::vector<int>&)>> sorting_algos = {
        {1, merge_sort_iterative},
        {2, merge_sort_recursive},
        {3, heap_sort},
        {4, quick_sort}
    };
    std::cerr << "\nChoose the algorithm to do the sorting:\n"
              << "1. Merge sort (iterative)\n"
              << "2. Merge sort (recursive)\n"
              << "3. Heap sort\n"
              << "4. Quick sort\n";
    int algo_num;
    std::cin >> algo_num;
    sorting_algos[algo_num](nums);
    
    std::cerr << "\nSorted list:";
    for (auto num : nums) {
        std::cout << std::to_string(num) << " ";
    }
    std::cout << std::endl;
    return 0;
}
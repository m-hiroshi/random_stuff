#include "quick_sort.hpp"

void helper(std::vector<int>& nums, int start, int end) {
    if (start+1 >= end) return;
    int pivot = end-1, left = start, right = end-2;
    while (left < right) {
        while (left < right && nums[left] <= nums[pivot]) ++left;
        while (left < right && nums[right] >= nums[pivot]) --right;
        if (left < right) std::swap(nums[left], nums[right]);
    }
    if (nums[right] > nums[pivot]) std::swap(nums[right], nums[pivot]);
    helper(nums, start, right);
    helper(nums, right+1, end);
}

void quick_sort(std::vector<int>& nums) {
    helper(nums, 0, nums.size());
}
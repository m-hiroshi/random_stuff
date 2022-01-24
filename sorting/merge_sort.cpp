#include "merge_sort.hpp"
#include <utility>

void helper(std::vector<int>& nums, int start, int end, std::vector<int>& helper_v) {
    if (start+1 >= end) return;
    int mid = start + (end - start) / 2;
    helper(nums, start, mid, helper_v);
    helper(nums, mid, end, helper_v);
    int i = start, j = start, k = mid;
    for (; i < end && j < mid && k < end; ++i) {
        if (nums[j] < nums[k]) helper_v[i] = nums[j++];
        else helper_v[i] = nums[k++];
    }
    if (i != end) {
        j = (k == end) ? j : k;
        while (i < end) helper_v[i++] = nums[j++];
    }
    for (i = start; i < end; ++i) nums[i] = helper_v[i];
}

void merge_sort(std::vector<int>& nums) {
    std::vector<int> helper_v(nums.size());
    helper(nums, 0, nums.size(), helper_v);
}
#pragma once

#include <vector>
#include <algorithm>

void sortColors(std::vector<int> &nums) {
    int n = nums.size();
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            std::swap(nums[i], nums[ptr]);
            ++ptr;
        }
    }
    for (int i = ptr; i < n; ++i) {
        if (nums[i] == 1) {
            std::swap(nums[i], nums[ptr]);
            ++ptr;
        }
    }
}
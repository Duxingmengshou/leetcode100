#pragma once

#include <vector>


int search(std::vector<int> &nums, int target) {
    auto ptr = std::find(nums.begin(), nums.end(), target);
    return ptr == nums.end() ? -1 : (ptr - nums.begin());
}
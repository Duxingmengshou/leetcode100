#pragma once

#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int> &nums) {
    std::next_permutation(nums.begin(), nums.end());
}
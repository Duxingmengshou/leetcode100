#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> searchRange(std::vector<int> &nums, int target) {
    auto ptrl = std::find(nums.begin(), nums.end(), target);
    auto ptrr = std::find(nums.rbegin(), nums.rend(), target);
    if (ptrl == nums.end())
        return std::vector<int>({-1, -1});
//    std::cout << ptrl - nums.begin() << std::endl;
//    std::cout << nums.size() - (ptrr - nums.rbegin() + 1) << std::endl;
    std::vector<int> res(2);
    res[0] = ptrl - nums.begin();
    res[1] = nums.size() - (ptrr - nums.rbegin() + 1);
    return res;
}

void check34() {
    std::vector<int> nums{5, 7, 7, 8, 8, 10};
    searchRange(nums, 8);
}

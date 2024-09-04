#pragma once


#include <vector>
#include <algorithm>
#include <iostream>

int rob(std::vector<int> &nums) {
    int gf1 = 0, gf2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = std::max(i >= 1 ? nums[i - 1] : gf1,
                           i >= 2 ? nums[i - 2] + nums[i] : gf2 + nums[i]);
    }
    return nums[nums.size() - 1];
}


void check198() {
    std::vector ll{2, 7, 9, 3, 1};
    rob(ll);
}
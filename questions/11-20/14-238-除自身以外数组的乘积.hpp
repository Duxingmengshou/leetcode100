#pragma once

#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> m1(nums.size(), 0), m2(nums.size(), 0);
    m1[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        m1[i] = m1[i - 1] * nums[i - 1];
    }
    m2[nums.size() - 1] = 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        m2[i] = m2[i + 1] * nums[i + 1];
    }
    std::vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        res[i] = m1[i] * m2[i];
    }
    return res;
}
#pragma once

#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int> &nums) {
    int res = nums[0];
    int sum = 0;
    for (auto &c: nums) {
        if (sum > 0)
            sum += c;
        else
            sum = c;
        res = std::max(res, sum);
    }
    return res;
}
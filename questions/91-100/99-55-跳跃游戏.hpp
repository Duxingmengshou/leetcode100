#pragma once

#include <vector>
#include <algorithm>

bool canJump(std::vector<int> &nums) {
    std::vector<int> dp(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        dp[i] = i + nums[i];
    }
    int max = INT_MIN;

    for (int i = 0; i < dp.size(); i++) {
        max = std::max(dp[i], max);
        if (max <= i && i != dp.size() - 1)
            return false;
    }
    return true;
}
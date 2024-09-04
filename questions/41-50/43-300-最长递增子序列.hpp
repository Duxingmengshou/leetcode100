#pragma once

#include <vector>
#include <iostream>


int lengthOfLIS(std::vector<int> &nums) {
    if (nums.size() == 1)
        return 1;
    std::vector<int> dp(nums.size(), 1);
    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j <= i - 1; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        if (res < dp[i])
            res = dp[i];
    }
    return res;
}

void check300() {
    std::vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << lengthOfLIS(v) << std::endl;
}
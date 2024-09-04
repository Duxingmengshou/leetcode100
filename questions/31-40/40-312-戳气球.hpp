#pragma once

#include <vector>
#include "../_pre/matrix.hpp"

int maxCoins(std::vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    std::vector<int> news(nums.size() + 2, 1);
    for (int i = 0; i < nums.size(); i++) {
        news[i + 1] = nums[i];
    }

    matrix<int> dp(news.size(), news.size());

    for (int i = r; i >= 0; i--) {
        for (int j = i + 2; j <= r + 2; j++) {
            if (i >= j - 1) {
                dp[i][j] = 0;
            } else {
                int tmp = INT_MIN;
                for (int k = i + 1; k <= j - 1; k++) {
                    tmp = std::max(tmp, news[i] * news[k] * news[j] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = tmp;
            }
        }
    }

    return dp[0][news.size() - 1];
}
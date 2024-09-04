#pragma once

#include <vector>

int maxProfit(std::vector<int> &prices) {
    if (prices.size() < 2)
        return 0;
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(3, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);//持有股票
        dp[i][1] = dp[i - 1][0] + prices[i];//不持有股票，处于冷冻期
        dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);//不持有股票，不处于冷冻期
    }
    return std::max(std::max(dp[prices.size()][0], dp[prices.size()][1]), dp[prices.size()][2]);

}
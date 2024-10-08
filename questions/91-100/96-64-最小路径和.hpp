#pragma once

#include <vector>
#include <algorithm>


int minPathSum(std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), INT_MAX));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < dp.size(); i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    }
    for (int i = 1; i < dp[0].size(); i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];

}

void check64() {
    std::vector<std::vector<int>> vv{{1, 2, 3},
                                     {4, 5, 6}};
    minPathSum(vv);
}
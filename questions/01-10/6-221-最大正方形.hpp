#pragma once

#include <vector>
#include <iostream>


int maximalSquare(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int res = 0;


    std::vector<std::vector<int>>
            dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));


    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                }
                if (dp[i][j] > res)
                    res = dp[i][j];
            }
        }
    }

    return res * res;
}
#pragma once

#include <vector>

int maxProfit1(std::vector<int> &prices) {
    int min = prices[0];
    std::vector<int> res(prices.size(), 0);
    for (int i = 1; i < res.size(); i++) {
        if (min > prices[i])
            min = prices[i];
        res[i] = std::max(prices[i] - min, res[i - 1]);
    }
    return res[res.size() - 1];

}
#pragma once

#include <vector>
#include <algorithm>
#include <unordered_set>

void dfs39(std::vector<int>::iterator begin,
           std::vector<int>::iterator end,
           int target, std::vector<int> rs,
           std::vector<std::vector<int>> &res) {
    if (target < 0)
        return;
    if (target == 0) {
        res.push_back(rs);
        return;
    }
    for (auto iter = begin; iter != end; iter++) {
        rs.push_back(*iter);
        dfs39(iter, end, target - *iter, rs, res);
        rs.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;
    dfs39(candidates.begin(), candidates.end(), target, tmp, res);
    return res;
}



#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

void dfs78(std::vector<int> &nums, int i, std::vector<int> cres,
           std::vector<std::vector<int>> &res) {
    if (nums.size() == i) {
        res.push_back(cres);
        return;
    }
    //不选
    dfs78(nums, i + 1, cres, res);
    //选
    cres.push_back(nums[i]);
    dfs78(nums, i + 1, cres, res);
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums) {

//    std::vector<int> state(nums.size(), 0);
    std::vector<int> cres;
    std::vector<std::vector<int>> res;
    dfs78(nums, 0, cres, res);
    return res;
}

void check78() {
    std::vector<int> nums{1, 2, 3};
    subsets(nums);
}

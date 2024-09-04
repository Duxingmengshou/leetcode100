#pragma once

#include <vector>
#include <iostream>
#include <algorithm>


std::vector<std::vector<int>> permute(std::vector<int> &nums) {

    std::vector<std::vector<int>> res;
    // sort(nums.begin(),nums.end());
    auto tmp = nums;
    res.push_back(nums);
    while (std::next_permutation(nums.begin(), nums.end())) {
        res.push_back(nums);
    }
    while (std::prev_permutation(tmp.begin(), tmp.end())) {
        res.push_back(tmp);
    }
    return res;

}
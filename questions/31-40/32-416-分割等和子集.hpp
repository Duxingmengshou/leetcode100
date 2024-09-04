#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "../_pre/matrix.hpp"

// dfs 超时
//void dfs416(std::vector<int> &nums, int sums, int i, bool &res) {
//    if (sums < 0)
//        return;
//    if (i == nums.size())
//        return;
//    if (sums == 0) {
//        res = true;
//        return;
//    }
//    //不取
//    dfs416(nums, sums, i + 1, res);
//    //取
//    dfs416(nums, sums - nums[i], i + 1, res);
//}
//
//
//bool canPartition(std::vector<int> &nums) {
//    int sums = 0;
//    for (auto c: nums)
//        sums += c;
//    if (sums % 2 == 1)
//        return false;
//    sums /= 2;
//    bool res = false;
//    dfs416(nums, sums, 0, res);
//    return res;
//}

bool canPartition(std::vector<int> &nums) {
    int sums = 0;
    for (auto c: nums)
        sums += c;
    if (sums % 2 == 1)
        return false;
    sums /= 2;
    if (*std::max_element(nums.begin(), nums.end()) > sums)
        return false;
    matrix<int> mx(nums.size(), sums + 1);
    for (int i = 0; i < nums.size(); i++) {
        mx[i][0] = 1;
    }
    mx[0][nums[0]] = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j < sums + 1; j++) {
            if (j >= nums[i]) {
                mx[i][j] = mx[i - 1][j] | mx[i - 1][j - nums[i]];
            } else {
                mx[i][j] = mx[i - 1][j];
            }
        }
    }
    return mx[nums.size() - 1][sums];

}

void check416() {
    std::vector<int> v{1, 5, 11, 5};
    std::cout << canPartition(v) << std::endl;
}
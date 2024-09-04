#pragma once

#include <vector>
#include <iostream>
#include <queue>

void bfs494(std::vector<int> &nums, int target, int &res) {
    res = 0;
    std::queue<int> qq, qi;
    qq.push(-nums[0]);
    qq.push(nums[0]);
    qi.push(0);
    qi.push(0);

    while (!qq.empty()) {
        auto cu = qq.front();
        qq.pop();
        auto index = qi.front();
        qi.pop();

        if (cu == target && index == nums.size() - 1)
            res++;
        if (index >= nums.size() - 1)
            continue;

        index++;
        qq.push(cu - nums[index]);
        qq.push(cu + nums[index]);
        qi.push(index);
        qi.push(index);
    }

}

void dfs494(std::vector<int> &nums, int target, int index, int sum, int &res) {
    if (index == nums.size()) {
        if (target == sum)
            res++;
        return;
    }
    dfs494(nums, target, index + 1, sum + nums[index], res);
    dfs494(nums, target, index + 1, sum - nums[index], res);
}

int findTargetSumWays(std::vector<int> &nums, int target) {
    int res{};
//    bfs494(nums, target, res);
    dfs494(nums, target, 0, 0, res);
    return res;
}

void check494() {
    std::vector<int> v{10, 34, 28, 5, 10, 26, 9, 17, 28, 10, 9, 6, 10, 15, 0, 28, 42, 39, 25, 19};//8034
    std::cout << findTargetSumWays(v, 26) << std::endl;

}
#pragma once

#include <vector>
#include <queue>

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
//    auto maxk = [&k](std::vector<int>::iterator itr) -> int {
//        return *std::max_element(itr, itr + k);
//    };
//    std::vector<int> res;
//    for (int i = 0; i < nums.size() - k; i++) {
//        res.push_back(maxk(nums.begin() + i));
//    }
    int n = nums.size();
    std::priority_queue<std::pair<int, int>> q;
    for (int i = 0; i < k; ++i) {
        q.emplace(nums[i], i);
    }
    std::vector<int> res = {q.top().first};
    for (int i = k; i < n; ++i) {
        q.emplace(nums[i], i);
        while (q.top().second <= i - k) {
            q.pop();
        }
        res.push_back(q.top().first);
    }

    return res;
}
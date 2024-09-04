#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    if (k >= nums.size())
        return nums;
    std::unordered_map<int, int> mm;
    for (auto c: nums)
        mm[c]++;


    std::vector<std::pair<int, int>> vp;

    for (auto c: mm) {
        vp.emplace_back(c.first, c.second);
    }


    std::sort(vp.begin(), vp.end(), [](auto a, auto b) {
        return a.second > b.second;
    });

    std::vector<int> res;

    for (int i = 0; i < k; i++) {
        res.emplace_back(std::move(vp[i].first));
    }
    return res;


}


void check347() {
    std::vector<int> v{1};
    topKFrequent(v, 1);

}
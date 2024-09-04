#pragma once

#include <vector>
#include <unordered_set>

std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
    std::unordered_set<int> ss;
    for (auto c: nums) {
        ss.insert(c);
    }
    std::vector<int> res;
    for (int i = 1; i <= nums.size(); i++) {
        if (!ss.count(i)) {
            res.push_back(i);
        }
    }
    return res;
}
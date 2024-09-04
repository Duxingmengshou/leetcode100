#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>


//std::vector<int> twoSum(std::vector<int> &nums, int target) {
//    std::unordered_map<int, std::vector<int>> mm;
//    for (int i = 0; i < nums.size(); i++) {
//        mm[nums[i]].push_back(i);
//    }
//    std::vector<int> res(2);
//    for (auto &c: mm) {
//        res[0] = c.second.back();
//        c.second.pop_back();
//        auto itr = mm.find(target - c.first);
//        if (itr != mm.end()) {
//            if (itr->second.empty())
//                continue;
//            res[1] = itr->second.back();
//            return res;
//        }
//    }
//    return res;
//}

std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hs;
    for (int i = 0; i < nums.size(); ++i) {
        if (hs.find(target - nums[i]) != hs.end())
            return {i, hs[target - nums[i]]};
        hs[nums[i]] = i;
    }
    return {-1, -1};
}
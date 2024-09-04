#pragma once

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

//void dfs15(std::vector<int>::iterator begin, std::vector<int>::iterator end,
//           int target, std::vector<int> cres,
//           std::set<std::vector<int>> &res) {
//
//    if (cres.size() > 3)//这个可以剪掉很多枝还是超时
//        return;
//    if (target == 0 && cres.size() == 3) {
//        std::sort(cres.begin(), cres.end());
//        res.insert(cres);
//    }
//    if (begin == end)
//        return;
//    //不取当前位置
//    dfs15(begin + 1, end, target, cres, res);
//    //取当前位置
//    cres.push_back(*begin);
//    dfs15(begin + 1, end, target - *begin, cres, res);
//}
//
//std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
//    std::vector<int> cres;
//    std::set<std::vector<int>> res;
//    std::vector<std::vector<int>> ress;
//    dfs15(nums.begin(), nums.end(), 0, cres, res);
//    for (auto c: res) {
//        ress.emplace_back(std::move(c));
//    }
//    return ress;
//}

// 直接搜索直接裂开

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::set<std::vector<int>> res;
    std::sort(nums.begin(), nums.end()); // 先排序

    for (size_t i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复元素

        size_t left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.insert({nums[i], nums[left], nums[right]});
                ++left;
                --right;

                // 跳过重复元素
                while (left < right && nums[left] == nums[left - 1]) ++left;
                while (left < right && nums[right] == nums[right + 1]) --right;
            } else if (sum < 0) {
                ++left; // 增加和
            } else {
                --right; // 减少和
            }
        }
    }

    return std::vector<std::vector<int>>(res.begin(), res.end());
}

void check15() {
    std::vector<int> v{34, 55, 79, 28, 46, 33, 2, 48, 31, -3, 84, 71, 52, -3, 93, 15, 21, -43, 57, -6, 86, 56, 94, 74,
                       83, -14, 28, -66, 46, -49, 62, -11, 43, 65, 77, 12, 47, 61, 26, 1, 13, 29, 55, -82, 76, 26, 15,
                       -29, 36, -29, 10, -70, 69, 17, 49};
    threeSum(v);

}
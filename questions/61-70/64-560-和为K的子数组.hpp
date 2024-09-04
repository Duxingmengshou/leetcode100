#pragma once

#include <vector>

//int subarraySum(std::vector<int> &nums, int k) {
//
//    int res = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        int sum = 0;
//        for (int j = i; j < nums.size(); j++) {
//            sum += nums[i];
//            if (sum == k) {
//                res++;
//                break;
//            }
//        }
//    }
//    return res;
//
//}

//必然超时
//巧用前缀和
#include <unordered_map>

int subarraySum(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto &x: nums) {
        pre += x;
        if (mp.count(pre - k)) {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}
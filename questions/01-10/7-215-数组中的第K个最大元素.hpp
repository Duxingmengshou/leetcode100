#pragma once

#include <iostream>
#include <vector>


void foo215(std::vector<int> &nums) {

    if (nums.size() <= 1)
        return;
    auto temp = nums[nums.size() / 2];

    std::vector<int> lv, rv, mv;


    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > temp) {
            lv.emplace_back(nums[i]);
        } else if (nums[i] < temp) {
            rv.emplace_back(nums[i]);
        } else {
            mv.emplace_back(temp);
        }
    }

    foo215(lv);
    foo215(rv);

    std::move(lv.begin(), lv.end(), nums.begin());
    std::move(mv.begin(), mv.end(), nums.begin() + lv.size());
    std::move(rv.begin(), rv.end(), nums.end() - rv.size());
}

int findKthLargest(std::vector<int> &nums, int k) {
    foo215(nums);
    return nums[k - 1];

}

void check215() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
    foo215(v);

    for (auto c: v) {
        std::cout << c << " ";
    }
    std::cout << "\n";
}
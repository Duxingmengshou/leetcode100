#pragma once

#include <vector>
#include <algorithm>
#include <iostream>


//void moveZeroes(std::vector<int> &nums) {
//    int j = nums.size() - 1, i = 0;
//    for (; i <= j; i++) {
//        if (nums[i] == 0) {
//            for (int k = i + 1; k <= j; k++) {
//                nums[k - 1] = nums[k];
//            }
//            nums[j--] = 0;
//        }
//
//    }
//}

void moveZeroes(std::vector<int> &nums) {
    int j = 0, i = 0;
    for (; i < nums.size(); i++) {
        if (nums[i] != 0 && i != j) {
            std::swap(nums[i], nums[j++]);
        }
    }
}

void check283() {
    std::vector<int> v{0,0, 1, 0, 3, 12};
    moveZeroes(v);
    for (auto c: v)
        std::cout << c << " ";
    std::cout << std::endl;
}
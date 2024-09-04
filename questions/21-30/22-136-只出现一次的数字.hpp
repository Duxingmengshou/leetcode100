#pragma once

#include <vector>
#include <queue>

int singleNumber(std::vector<int> &nums) {
    // -3 * 10^4 <= nums[i] <= 3 * 10^4
    std::vector<int> buf(60001, 0); // 记录每个数字出现的次数

    int max = -1;
    for (auto c: nums) {
        buf[c + 30000]++; // 将数字映射到 buf 数组中
        if (c + 30000 > max) {
            max = c + 30000;
        }
    }

    for (int i = 0; i < max; ++i) {
        if (buf[i] == 1) { // 找到出现一次的数字
            return i - 30000; // 返回原始数字
        }
    }

    return 0; // 如果没有找到，返回 0（可以根据需求修改）
}
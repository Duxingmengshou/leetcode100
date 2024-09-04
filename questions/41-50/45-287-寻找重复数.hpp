#pragma once

#include <vector>

int findDuplicate(std::vector<int> &nums) {
    static std::vector<int> vv(100005, 0);
    std::fill(vv.begin(), vv.end(), 0);
    for (auto c: nums) {
        vv[c]++;
        if (vv[c] > 1)
            return c;
    }
    return 0;
}
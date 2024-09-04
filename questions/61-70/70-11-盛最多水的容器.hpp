#pragma once

#include <vector>
#include <stack>
#include <deque>
#include <algorithm>

int maxArea(std::vector<int> &height) {
    int res = 0;
    for (int i = 0, j = height.size() - 1; i < j;) {
        int area = std::min(height[i], height[j]) * (j - i);
        res = std::max(res, area);
        if (height[i] <= height[j]) {
            ++i;
        } else {
            --j;
        }
    }
    return res;
}
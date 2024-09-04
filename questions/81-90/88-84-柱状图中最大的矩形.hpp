#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

//暴力解法超时
//int largestRectangleArea(std::vector<int> &heights) {
//    int res = 0;
//    for (int i = 0; i < heights.size(); i++) {
//        int h = heights[i];
//        for (int j = i; j < heights.size(); j++) {
//            h = std::min(heights[j], h);
//            res = res > h * (j - i + 1) ? res : h * (j - i + 1);
//        }
//    }
//    return res;
//}

int largestRectangleArea(std::vector<int> &heights) {
    int n = heights.size();
    std::vector<int> left(n), right(n);

    std::stack<int> mono_stack;
    for (int i = 0; i < n; ++i) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            mono_stack.pop();
        }
        left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
        mono_stack.push(i);
    }

    mono_stack = std::stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            mono_stack.pop();
        }
        right[i] = (mono_stack.empty() ? n : mono_stack.top());
        mono_stack.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
}
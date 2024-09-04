#pragma once

#include <vector>
#include <stack>
#include <deque>
#include <iostream>

//int trap(std::vector<int> &height) {
//    std::deque<int> st;
//    int res = 0;
//    int max = *std::max_element(height.begin(), height.end());
//    for (int i = 1; i <= max; i++) {
//        for (int j = 0; j < height.size(); j++) {
//            if (height[j] >= i) {
//                st.push_back(j);
//            }
//            if (st.size() == 2) {
//                int x = st.front();
//                st.pop_front();
//                int y = st.front();
//                st.pop_front();
//                res += (y - x - 1);
//                st.push_back(y);
//            }
//        }
//        while (!st.empty()) {
//            st.pop_front();
//        }
//    }
//    return res;
//}

//int trap(std::vector<int> &height) {
//    std::deque<int> st;
//    int res = 0;
//    int max = *std::max_element(height.begin(), height.end());
//    for (int i = 1; i <= max; i++) {
//        for (int j = 0; j < height.size(); j++) {
//            if (height[j] >= i) {
//                st.push_back(j);
//            }
//        }
//        while (!st.empty()) {
//            int x = st.front();
//            st.pop_front();
//            if (st.empty())
//                break;
//            int y = st.front();
//            res += (y - x - 1);
//        }
//    }
//    return res;
//}

int trap(std::vector<int> &height) {
    int ans = 0;
    std::stack<int> st;
    for (int i = 0; i < height.size(); ++i) {
        while (!st.empty() && height[i] >= height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int left = st.top();
            int currWidth = i - left - 1;
            int currHeight = std::min(height[left], height[i]) - height[top];
            ans += currWidth * currHeight;
        }
        st.push(i);
    }
    return ans;
}

void check42() {
    std::vector<int> v{0,1,0,3,1,0,1,3,2,1,2,1};
    std::cout << trap(v) << std::endl;
}
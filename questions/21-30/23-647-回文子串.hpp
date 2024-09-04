#pragma once

#include <string>

int countSubstrings(std::string s) {
    //长度为 n 的字符串会生成 2n−1 组回文中心 [li,ri], li=i/2, ri=i/2+i%2
    int n = s.size(), ans = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        int l = i / 2, r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
            ++ans;
        }
    }
    return ans;
}
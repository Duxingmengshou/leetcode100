#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

//前后指针，遇到重复移动后指针到适当位置
int lengthOfLongestSubstring(std::string s) {
    std::vector<int> mm(1000, 0);
    int res = 0;
    for (int i = 0, j = i; i < s.size(); i++) {
        if (mm[s[i]] == 0) {
            if (res < i - j + 1) {
                res = i - j + 1;
            }
            mm[s[i]]++;
        } else {
            mm[s[i]]++;
            while (s[j] != s[i])
                mm[s[j++]]--;
            if (j < i)
                mm[s[j++]]--;
        }
    }
    return res;
}


void check3() {
    std::cout << lengthOfLongestSubstring("dvdf") << std::endl;
}

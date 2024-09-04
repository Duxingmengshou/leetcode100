#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

//很多特殊情况无法覆盖
//std::string minWindow(std::string s, std::string t) {
//    std::unordered_map<char, int> mm;
//    for (auto &c: t) {
//        mm[c] = -1;
//    }
//    int l = 0, r = s.size();
//    for (int i = 0; i < s.size(); i++) {
//        //找到
//        if (mm.find(s[i]) != mm.end()) {
//            mm[s[i]] = i;
//            int tmpl = i, tmpr = i;
//            bool isB = false;
//            for (auto &c: mm) {
//                if (c.second == -1) {
//                    isB = true;
//                    break;
//                }
//                tmpl = std::min(tmpl, c.second);
//            }
//            if (!isB && tmpl != -1 && (tmpr - tmpl) < (r - l)) {
//                l = tmpl, r = tmpr;
//                std::cout << tmpl << "-" << tmpr << std::endl;
//            }
//        }
//    }
//    return l == r ? "" : s.substr(l, r - l + 1);
//}


///找到一个有效的窗口后，能够尽量缩小窗口的左边界
std::string minWindow(std::string s, std::string t) {
    if (s.size() < t.size()) return "";

    std::unordered_map<char, int> charCount;
    for (char c: t) {
        charCount[c]++;
    }

    int required = charCount.size();
    int formed = 0;
    std::unordered_map<char, int> windowCounts;

    int l = 0, r = 0;
    int minLength = INT_MAX;
    int minLeft = 0;

    while (r < s.size()) {
        char c = s[r];
        windowCounts[c]++;

        if (charCount.count(c) && windowCounts[c] == charCount[c]) {
            formed++;
        }

        while (l <= r && formed == required) {
            c = s[l];

            // Update the minimum window
            if (r - l + 1 < minLength) {
                minLength = r - l + 1;
                minLeft = l;
            }

            windowCounts[c]--;
            if (charCount.count(c) && windowCounts[c] < charCount[c]) {
                formed--;
            }
            l++;
        }
        r++;
    }

    return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
}

void check76() {
    std::string s{"A"}, t{"C"};
    std::cout << minWindow(s, t) << std::endl;
}
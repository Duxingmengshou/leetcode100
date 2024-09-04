#pragma once

#include <string>
#include <iostream>


//bool foo5(const std::string &str, int l, int r) {
//    while (l <= r) {
//        if (str[l] != str[r]) {
//            return false;
//        }
//        l++, r--;
//    }
//    return true;
//}
//
//void dfs5(std::string &s, int l, int r, std::string &res) {
//    if (l >= r) {
//        return;
//    }
//    if (foo5(s, l, r)) {
//        if (res.size() < r - l + 1) {
//            res = s.substr(l, r - l + 1);
//        }
//        return;
//    }
//    dfs5(s, l + 1, r, res);
//    dfs5(s, l, r - 1, res);
//}
//
//std::string longestPalindrome(std::string s) {
//    std::string str;
//    dfs5(s, 0, s.size() - 1, str);
//    return str == "" ? s.substr(0, 1) : str;
//}

// 直接搜索超时，使用中心扩展法
int expandAroundCenter(const std::string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}

std::string longestPalindrome(std::string s) {
    if (s.empty()) return "";
    int start = 0, end = 0;

    for (int i = 0; i < s.size(); i++) {
        int len1 = expandAroundCenter(s, i, i);   // Odd length
        int len2 = expandAroundCenter(s, i, i + 1); // Even length
        int len = std::max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}


void check5() {
    std::cout << longestPalindrome("babad");
//    std::cout << foo5("aba", 0, 2);
}
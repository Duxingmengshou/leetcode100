#pragma once

#include <string>
#include <stack>
#include <vector>
#include <iostream>

//int longestValidParentheses(std::string s) {
//    auto isV = [](const std::string &s) {
//        std::stack<char> st;
//        for (auto &c: s) {
//            if (!st.empty() && st.top() == '(' && c == ')')
//                st.pop();
//            else
//                st.push(c);
//        }
//        return st.empty();
//    };
//
//    std::cout << isV(s) << std::endl;
//    int res = 0;
//
//    for (int i = 0; i < s.size(); i++) {
//        for (int j = 1; j < s.size() - i; j++) {
//            if (isV(s.substr(i, j))) {
//                if (j > res)
//                    res = j;
//            }
//        }
//    }
//
//    return res;
//}

int longestValidParentheses(std::string s) {
    if (s.size() <= 1)
        return 0;
    std::vector<int> res(s.size(), 0);
    int tmp = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                res[i] = (i >= 2 ? res[i - 2] : 0) + 2;
            } else if (i - res[i - 1] > 0 && s[i - res[i - 1] - 1] == '(') {
                res[i] =
                        res[i - 1] +
                        ((i - res[i - 1]) >= 2 ? res[i - res[i - 1] - 2] : 0) +
                        2;
            }
        }
        tmp > res[i] ? tmp : tmp = res[i];
    }
    return tmp;
}


void check32() {
    std::string str = "()()(()";
    longestValidParentheses(str);
}
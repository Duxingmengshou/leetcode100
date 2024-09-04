#pragma once

#include <vector>
#include <string>
#include <unordered_set>

#include <iostream>

bool isV301(std::string s) {
    int count = 0;
    for (auto c: s) {
        if (c == '(')
            count++;
        if (c == ')') {
            count--;
            if (count < 0)
                return false;
        }
    }
    return count == 0;
}

std::vector<std::string> removeInvalidParentheses(std::string s) {

    std::vector<std::string> res;
    std::unordered_set<std::string> ss;
    ss.insert(s);

    while (true) {
        for (auto &str: ss) {
            if (isV301(str))
                res.emplace_back(str);
        }
        if (res.size() > 0) {
            return res;
        }
        std::unordered_set<std::string> nextSet;
        for (auto &str: ss) {
            for (int i = 0; i < str.size(); i++) {
                if (i > 0 && str[i] == str[i - 1]) {
                    continue;
                }
                if (str[i] == '(' || str[i] == ')') {
                    nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
                }
            }
        }
        ss = nextSet;
    }
    return res;
}
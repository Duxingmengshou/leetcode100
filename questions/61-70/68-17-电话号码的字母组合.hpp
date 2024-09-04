#pragma once

#include <vector>
#include <string>

void foo17(std::string digits, std::string buf,
           std::vector<std::string> &m, std::vector<std::string> &res) {
    if (digits.empty()) {
        return;
    }
    if (digits.size() == 1) {
        for (auto c: m[digits[0] - '0']) {
            res.push_back(buf + c);
        }
        return;
    }
    std::string tmpDigits = digits.substr(1, digits.size() - 1);
    for (auto c: m[digits[0] - '0']) {
        foo17(tmpDigits, buf + c, m, res);
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> vv{
            {},
            {},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
    };
    std::vector<std::string> res;
    std::string str;
    foo17(digits, str, vv, res);
    return res;
}
#pragma once

#include <iostream>
#include <vector>
#include <string>


std::vector<int> findAnagrams(std::string s, std::string p) {
    int sLen = s.size(), pLen = p.size();

    if (sLen < pLen) {
        return {};
    }

    std::vector<int> ans, sCount(26), pCount(26);
    for (int i = 0; i < pLen; ++i) {
        ++sCount[s[i] - 'a'];
        ++pCount[p[i] - 'a'];
    }

    if (sCount == pCount) {
        ans.emplace_back(0);
    }

    for (int i = 0; i < sLen - pLen; ++i) {
        --sCount[s[i] - 'a'];
        ++sCount[s[i + pLen] - 'a'];

        if (sCount == pCount) {
            ans.emplace_back(i + 1);
        }
    }

    return ans;
}
#pragma once

#include <string>
#include <vector>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string> &wordDict) {

    //dp[i]=dp[j] && check(s[j..i−1])
    std::unordered_set<std::string> dictSet;
    for (auto c: wordDict) {
        dictSet.insert(c);
    }

    std::vector<int> res(s.size() + 1, 0);
    res[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (res[j] && dictSet.find(s.substr(j, i - j)) != dictSet.end()) {
                res[i] = true;
                break;
            }
        }
    }
    return res[s.size()] == 1;
}


#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

//std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
//    if (strs.size() == 1) {
//        return std::vector<std::vector<std::string>>{strs};
//    }
//
//
//    auto isF = [](std::string &a, std::string &b) {
//        std::vector<char> va(26, 0);
//        std::vector<char> vb(26, 0);
//        for (auto &c: a) {
//            va[c - 'a']++;
//        }
//        for (auto &c: b) {
//            vb[c - 'a']++;
//        }
//        return va == vb;
//    };
//    std::vector<std::vector<std::string>> res;
//    for (auto &c: strs) {
//        bool isFind = false;
//        for (auto &cc: res) {
//            if (isF(c, cc[0])) {
//                isFind = true;
//                cc.emplace_back(std::move(c));
//                break;
//            }
//        }
//        if (!isFind) {
//            res.emplace_back(std::vector<std::string>({std::move(c)}));
//        }
//    }
//
//    return res;
//}

//std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
//    std::vector<std::string> temps = strs;
//    for (auto &c: temps) {
//        std::sort(c.begin(), c.end());
//    }
//    std::vector<std::vector<std::string>> res;
//    std::vector<int> vv(strs.size(), 0);
//    for (int i = 0; i < strs.size(); i++) {
//        std::vector<std::string> temp;
//        if (vv[i] == 0) {
//            temp.emplace_back(std::move(strs[i]));
//            vv[i] = 1;
//        }
//        for (int j = i + 1; j < strs.size(); j++) {
//            if (temps[i] == temps[j] && vv[j] == 0) {
//                vv[j] = 1;
//                temp.emplace_back(std::move(strs[j]));
//            }
//        }
//        if (!temp.empty())
//            res.emplace_back(std::move(temp));
//    }
//    return res;
//}


std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    if (strs.size() == 1) {
        return std::vector<std::vector<std::string>>{strs};
    }

    std::unordered_map<std::string, std::vector<std::string>> mm;

    for (auto &c: strs) {
        auto tmp = c;
        std::sort(tmp.begin(), tmp.end());
        mm[tmp].emplace_back(std::move(c));
    }
    std::vector<std::vector<std::string>> res;
    for (auto &c: mm) {
        res.emplace_back(c.second.begin(), c.second.end());
    }
    return res;

}

void check49() {
    std::vector<std::string> v{"eat", "tea", "tan", "ate", "nat", "bat"};

    groupAnagrams(v);
}
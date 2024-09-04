#pragma once

#include <vector>
#include <unordered_set>
#include <iostream>

int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> ss;
    for (auto c: nums) {
        ss.insert(c);
    }
    int res = 0;
    for (auto c: ss) {
        if (!ss.count(c - 1)) {
            int cures = 1;
            c++;
            while (ss.count(c)) {
                cures++;
                c++;
            }
            res = std::max(cures, res);
        }
    }
    return res;
}


void check128() {
    std::vector<int> vv{100, 4, 200, 1, 3, 2};
    std::cout << longestConsecutive(vv) << std::endl;
}
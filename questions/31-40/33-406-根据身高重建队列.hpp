#pragma once

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people) {
    std::sort(people.begin(), people.end(), [](std::vector<int> a, std::vector<int> b) {
        return (a[0] < b[0]) || ((a[0] == b[0]) && a[1] > b[1]);
    });
    int n = people.size();
    std::vector<std::vector<int>> ans(n);
    for (auto &person: people) {
        int spaces = person[1] + 1;
        for (int i = 0; i < n; ++i) {
            if (ans[i].empty()) {
                --spaces;
                if (!spaces) {
                    ans[i] = person;
                    break;
                }
            }
        }
    }
    return ans;
}

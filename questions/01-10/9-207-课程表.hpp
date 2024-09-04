#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {

    std::queue<int> s;
    std::unordered_map<int, std::vector<int>> mm;//入度不为零的节点的前驱节点
    std::vector<int> tempv(numCourses, 0);//

    for (int i = 0; i < prerequisites.size(); i++) {
        mm[prerequisites[i][0]].emplace_back(prerequisites[i][1]);
        tempv[prerequisites[i][0]]++;
    }
    for (int i = 0; i < numCourses; i++) {
        if (tempv[i] == 0)
            s.push(i);
    }

    while (!s.empty()) {
        auto tmp = s.front();
        s.pop();
        for (auto &c: mm) {
            if (c.second.empty()) {
                continue;
            }
            auto ptr = std::find(c.second.begin(), c.second.end(), tmp);
            if (ptr != c.second.end()) {
                c.second.erase(ptr);
                tempv[c.first]--;
            }
            if (c.second.empty()) {
                s.push(c.first);
            }
        }
    }
    for (auto c: tempv) {
        if (c != 0)
            return false;
    }
    return true;
}

void check207() {
    std::vector<std::vector<int>> vv = {{1, 0}};
    std::cout << canFinish(2, vv);

}
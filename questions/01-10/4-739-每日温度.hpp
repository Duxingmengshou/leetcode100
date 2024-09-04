#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {

//    std::vector<int> res(temperatures.size(), 0);
//    std::unordered_map<int, int> mm;
//    for (int i = 0, j = 1; i < temperatures.size() - 1; i++, j++) {
//        for (auto &m: mm) {
//            if (m.second == -1) {
//                continue;
//            }
//            if (temperatures[m.first] < temperatures[j]) {
//                res[m.first] = ++m.second;
//                m.second = -1;
//            } else {
//                m.second++;
//            }
//        }
//        if (temperatures[i] < temperatures[j]) {
//            res[i] = 1;
//        } else {
//            mm[i]++;
//        }
//    }
//    return res;

    std::vector<int> res(temperatures.size(), 0);
    std::stack<int> ss;
    for (int i = 0; i < temperatures.size(); i++) {

        while (!ss.empty() && temperatures[i] > temperatures[ss.top()]) {//慢计算
            auto index = ss.top();
            ss.pop();
            res[index] = i - index;
        }


        ss.push(i);
    }
    return res;

}
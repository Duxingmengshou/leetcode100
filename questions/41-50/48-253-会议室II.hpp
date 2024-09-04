#pragma once


#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

int minMeetingRooms(std::vector<std::vector<int>> &intervals) {

    std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &a, std::vector<int> &b) { return a[0] < b[0]; });
    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    for (auto &interval: intervals) {
        if (!que.empty() && interval[0] >= que.top()) {
            que.pop();
        }
        que.push(interval[1]);
    }
    return que.size();
}


void check253() {
    std::vector<std::vector<int>> v{{0,  30},
                                    {5,  10},
                                    {15, 20}};
    std::cout<<minMeetingRooms(v)<<std::endl;
}
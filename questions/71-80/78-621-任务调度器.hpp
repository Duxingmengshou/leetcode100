#pragma once

#include <vector>
#include <unordered_map>
#include <queue>

int leastInterval(std::vector<char>& tasks, int n) {
    std::unordered_map<char, int> taskCount;
    for (char task : tasks) {
        taskCount[task]++;
    }

    // 最大堆，存储任务的频率
    std::priority_queue<int> maxHeap;
    for (auto& entry : taskCount) {
        maxHeap.push(entry.second);
    }

    int time = 0;
    while (!maxHeap.empty()) {
        std::vector<int> temp;
        // 每个周期处理 n + 1 个任务
        for (int i = 0; i <= n; i++) {
            if (!maxHeap.empty()) {
                temp.push_back(maxHeap.top());
                maxHeap.pop();
            }
        }

        // 处理完的任务
        for (int count : temp) {
            if (--count > 0) {
                maxHeap.push(count);
            }
        }

        // 如果 maxHeap 为空，说明所有任务都已完成
        time += maxHeap.empty() ? temp.size() : n + 1;
    }

    return time;
}
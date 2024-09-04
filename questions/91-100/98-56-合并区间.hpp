#pragma once

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.empty()) return {};

    // 按照区间的开始值进行排序
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> merged;
    std::vector<int> current = intervals[0];

    for (const auto &interval : intervals) {
        if (interval[0] <= current[1]) { // 有重叠
            current[1] = std::max(current[1], interval[1]); // 更新结束值
        } else { // 无重叠
            merged.push_back(current); // 保存当前区间
            current = interval; // 更新当前区间
        }
    }
    merged.push_back(current); // 添加最后一个区间

    return merged;
}
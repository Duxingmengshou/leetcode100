#pragma once

#include <iostream>
#include <algorithm>
#include <vector>


/*
 *       左段有序   中段无序   右段有序
         所以 中段里面的最小值 比 左段里面的最大值 还要大    即中段里面的所有值都比它大
             中段里面的最大值 比  右段里面的最小值 还要小   即中段里面的所有值都比它小

         因此 从左到右  找最大值  这期间如果有值比最大值还要小 那么这个值就有可能是 中段的右边界
                因为升序的时候（左右段） 最大值一直在替换，所以最后一个小  它就是 中段的右边界
         因此 从右到左  找最小值  这期间如果有值比最小值还要大 那么这个值就有可能是 中段的左边界
                因为降序的时候（左右段） 最小值一直在替换，所以最后一个大 它就是 中段的左边界
 * */
int findUnsortedSubarray(std::vector<int> &nums) {
    if (std::is_sorted(nums.begin(), nums.end()))
        return 0;
    auto l = nums.begin(), r = nums.end() - 1;
    int op = 0;
    while (l <= r) {
        op = 0;
        if (*l <= *std::min_element(l + 1, r + 1)) {
            l++;
            op++;
        }
        if (*r >= *std::max_element(l, r)) {
            r--;
            op++;
        }
        if (op == 0)
            break;
    }
    return r - l;
}

void check581() {
    std::vector<int> v{2, 6, 4, 8, 10, 9, 15};
    findUnsortedSubarray(v);
}
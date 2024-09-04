#pragma once

#include <vector>
#include <iostream>

int maxProduct(std::vector<int> &nums) {
    std::vector<long long int>
            maxres(nums.begin(),
                   nums.end()),
            minres(nums.begin(),
                   nums.end());
    for (int i = 1; i < nums.size(); i++) {
        maxres[i] = std::max(std::max(maxres[i - 1] * nums[i], (long long int) nums[i]),
                             minres[i - 1] * nums[i]);
        minres[i] = std::min(std::min(minres[i - 1] * nums[i], (long long int) nums[i]),
                             maxres[i - 1] * nums[i]);
        if (minres[i] < INT_MIN) {
            minres[i] = nums[i];
        }
    }
    return (int) *std::max_element(maxres.begin(), maxres.end());

}

void check152() {
    std::vector<int> v{2, 3, -2, 4};
    std::cout << maxProduct(v) << std::endl;
}
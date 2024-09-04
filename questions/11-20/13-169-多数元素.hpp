#pragma once

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

int majorityElement(std::vector<int> &nums) {
    std::unordered_map<int, int> mm;

    int res = 0, ress = nums[0];
    for (auto c: nums) {
        mm[c]++;
        if (mm[c] > res)
            res = mm[c], ress = c;
    }
    for (auto cc: mm) {

        std::cout << cc.first << "-" << cc.second << " ";
    }
    std::cout << " " << res << "\n";

    return ress;
}


void check169() {
    std::vector<int> v{3, 2, 3};
    majorityElement(v);

}

/*
 *     map<int,int> res;
    int majorityElement(vector<int>& nums) {
        for(auto c:nums)
        {
            res[c]++;
        }
        auto res1=res.begin();
        for(auto i=res.begin();i!=res.end();i++)
        {
            if(i->second>res1->second)
            {
                res1=i;
            }
        }
        return res1->first;
    }*/
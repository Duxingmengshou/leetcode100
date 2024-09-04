#pragma once

#include <vector>
#include <iostream>

std::vector<int> countBits(int n) {
    std::vector<int> res;
    auto ff = [](int u) {
        u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
        u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
        u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
        u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
        u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
        return u;
    };
    for (int i = 0; i <= n; i++)
//        res.emplace_back(__builtin_popcount(i));
        res.emplace_back(ff(i));
    return res;
}

void check338() {
    auto c = countBits(5);
    for (auto cc: c) {
        std::cout << cc << " ";
    }
    std::cout << std::endl;
}
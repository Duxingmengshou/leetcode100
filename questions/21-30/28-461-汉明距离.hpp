#pragma once

#include <iostream>


int hammingDistance(int x, int y) {
    auto z = x ^ y;
//    return __builtin_popcount(z);
    int res = 0;
    while (z) {
        res += z & 1;
        z >>= 1;
    }
    return res;
}

void check461() {
    std::cout << hammingDistance(1, 4) << std::endl;
}
#pragma once

#include <iostream>
#include <string>
#include <fstream>

int init = [] {
    // 取消同步，提升 cin 和 cout 的性能
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    return 0;
}();
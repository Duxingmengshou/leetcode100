#pragma once

#include <vector>

// 应该是每四次一个循环，不过这样有点复杂，可以先翻转，之后交换，这样好理解
void rotate(std::vector<std::vector<int>> &matrix) {
    for (int i = 0, j = matrix.size() - 1; i < j; i++, j--) {
        std::swap(matrix[i], matrix[j]);
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < i; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}
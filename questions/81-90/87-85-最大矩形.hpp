#include <iostream>
#include <vector>
#include <algorithm>

//纯暴力超时
//int maximalRectangle(vector<vector<char>> &matrix) {
//    if (matrix.empty() || matrix[0].empty()) return 0;
//
//    int rows = matrix.size();
//    int cols = matrix[0].size();
//    int maxArea = 0;
//
//    // 遍历每一个点作为左上角
//    for (int top = 0; top < rows; ++top) {
//        for (int left = 0; left < cols; ++left) {
//            if (matrix[top][left] == '1') {
//                // 以 (top, left) 为左上角，寻找最大矩形
//                for (int bottom = top; bottom < rows; ++bottom) {
//                    // 记录当前行的有效右边界
//                    int right = left;
//                    while (right < cols && matrix[bottom][right] == '1') {
//                        // 检查从 top 到 bottom 的每一行
//                        bool valid = true;
//                        for (int i = top; i <= bottom; ++i) {
//                            if (matrix[i][right] == '0') {
//                                valid = false;
//                                break;
//                            }
//                        }
//                        // 如果有效，计算面积
//                        if (valid) {
//                            int area = (bottom - top + 1) * (right - left + 1);
//                            maxArea = max(maxArea, area);
//                        } else {
//                            break; // 一旦发现无效，停止检查
//                        }
//                        right++; // 向右扩展
//                    }
//                }
//            }
//        }
//    }
//
//    return maxArea;
//}
int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    int m = matrix.size();
    if (m == 0) {
        return 0;
    }
    int n = matrix[0].size();
    std::vector<std::vector<int>> left(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '0') {
                continue;
            }
            int width = left[i][j];
            int area = width;
            for (int k = i - 1; k >= 0; k--) {
                width = std::min(width, left[k][j]);
                area = std::max(area, (i - k + 1) * width);
            }
            ret = std::max(ret, area);
        }
    }
    return ret;
}

int check85() {
    std::vector<std::vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

    int maxRectangleArea = maximalRectangle(matrix);
    std::cout << "最大矩形的面积: " << maxRectangleArea << std::endl;

    return 0;
}

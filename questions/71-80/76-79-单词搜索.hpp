#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <set>


//对于每个位置，都作为起点进行一遍搜索
void bfs79(std::vector<std::vector<char>> &board, std::string word,
           std::vector<std::vector<bool>> &visited, int index, int x, int y, bool &res) {
    if (res)
        return;
    if (index == word.size()) {
        res = true;
        return;
    }
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[index]) {
        return;
    }

    visited[x][y] = true; // 标记为已访问
    // 递归搜索四个方向
    bfs79(board, word, visited, index + 1, x - 1, y, res); // 上
    bfs79(board, word, visited, index + 1, x + 1, y, res); // 下
    bfs79(board, word, visited, index + 1, x, y - 1, res); // 左
    bfs79(board, word, visited, index + 1, x, y + 1, res); // 右
    visited[x][y] = false; // 回溯，标记为未访问
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
    bool res = false;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            bfs79(board, word, visited, 0, i, j, res);
            if (res) return true; // 提前返回
        }
    }
    return res;
}

void check79() {
    std::vector<std::vector<char>> v{{'A', 'B'},
                                     {'S', 'F'}};
    exist(v, "BF");
}
#pragma once

#include <vector>
#include <iostream>


void dfs200(std::vector<std::vector<char>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
        return;
    }
    if (grid[i][j] == '0')
        return;

    grid[i][j] = '0';
    dfs200(grid, i - 1, j);
    dfs200(grid, i, j - 1);
    dfs200(grid, i + 1, j);
    dfs200(grid, i, j + 1);

}


int numIslands(std::vector<std::vector<char>> &grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                res++;
                dfs200(grid, i, j);
            }
        }
    }
    return res;
}
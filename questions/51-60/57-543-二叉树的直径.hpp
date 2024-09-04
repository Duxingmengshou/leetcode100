#pragma once

#include "../header/TreeNode.hpp"
#include <algorithm>

void dfs543(TreeNode *root, int length, int &max) {
    if (!root) {
        if (max < length)
            max = length;
        return;
    }
    dfs543(root->left, length + 1, max);
    dfs543(root->right, length + 1, max);
}

int foo543(TreeNode *root) {
    if (!root)
        return 0;
    int maxL = 0;
    dfs543(root->left, 0, maxL);
    int maxR = 0;
    dfs543(root->right, 0, maxR);
    return maxL + maxR;
}

void foodfs543(TreeNode *root, int &res) {
    if (root == nullptr)
        return;
    int tmp = foo543(root);
    if (tmp > res) {
        res = tmp;
    }
    foodfs543(root->left, res);
    foodfs543(root->right, res);
}

int f543(TreeNode *root, int &res) {
    if (!root)
        return 0;
    int maxL = f543(root->left, res);
    int maxR = f543(root->right, res);

    res = std::max(res, maxL + maxR + 1);
    return std::max(maxL, maxR) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
    int res = 0;
//    foodfs543(root, res);
    f543(root, res);
    return res;
}
#pragma once

#include "../header/TreeNode.hpp"

void dfs104(TreeNode *root, int cres, int &res) {
    if (root == nullptr)
        return;
    if (cres > res) {
        res = cres;
    }
    dfs104(root->left, cres + 1, res);
    dfs104(root->right, cres + 1, res);
}

int maxDepth(TreeNode *root) {
    int res = 0;
    dfs104(root, 1, res);
    return res;
}
#pragma once

#include <vector>
#include <algorithm>
#include "../header/TreeNode.hpp"


void dfs94(TreeNode *root, std::vector<int> &res) {
    if (root == nullptr)
        return;
    dfs94(root->left, res);
    res.emplace_back(std::move(root->val));
    dfs94(root->right, res);
}

std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    dfs94(root, res);
    return res;
}
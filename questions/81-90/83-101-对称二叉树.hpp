#pragma once

#include "../header/TreeNode.hpp"
#include <string>

void dfs101(TreeNode *root, int i, std::string &s) {
    if (root == nullptr)
        return;
    dfs101(root->left, i + 1, s);
    s += (char) i;
    s += (char) root->val;
    s += (char) i;
    dfs101(root->right, i + 1, s);
}

bool isSymmetric(TreeNode *root) {
    std::string s;
    dfs101(root, 1, s);
    std::string tmp(s.rbegin(), s.rend());
    return tmp == s;
}
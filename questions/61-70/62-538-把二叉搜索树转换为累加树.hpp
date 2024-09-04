#pragma once

#include <vector>
#include "../header/TreeNode.hpp"

long long int dfs538(TreeNode *root, long long int &base) {
    if (!root)
        return 0;
    // 先遍历右子树
    long long int r = dfs538(root->right, base);
    // 更新当前节点的值
    base += root->val;
    root->val = base;
    // 继续遍历左子树
    long long int l = dfs538(root->left, base);
    return l + r + root->val; // 返回当前节点的值
}

TreeNode *convertBST(TreeNode *root) {
    long long int base = 0;
    dfs538(root, base);
    return root;
}
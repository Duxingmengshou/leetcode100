#pragma once

#include <iostream>
#include "../header/TreeNode.hpp"


int dfs437(TreeNode *root, long long int targetSum) {
    if (!root) {
        return 0;
    }
    long long int ret = 0;
    if (root->val == targetSum)
        ret++;

    ret += dfs437(root->left, targetSum - root->val);
    ret += dfs437(root->right, targetSum - root->val);
    return ret;
}

int pathSum(TreeNode *root, int targetSum) {
    if (!root) {
        return 0;
    }
    long long int res = 0;
    res += dfs437(root, targetSum);
    res += pathSum(root->right, targetSum);
    res += pathSum(root->left, targetSum);
    return res;
}
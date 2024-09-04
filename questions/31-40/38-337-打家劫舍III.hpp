#pragma once

#include <unordered_map>
#include <algorithm>
#include "../header/TreeNode.hpp"

void dfs337(TreeNode *ptr, std::unordered_map<TreeNode *, int> &mf, std::unordered_map<TreeNode *, int> &mg) {
    if (!ptr)
        return;
    dfs337(ptr->left, mf, mg);
    dfs337(ptr->right, mf, mg);
    mf[ptr] = ptr->val + mg[ptr->left] + mg[ptr->right];//选ptr节点
    mg[ptr] = std::max(mf[ptr->left], mg[ptr->left]) + std::max(mf[ptr->right], mg[ptr->right]);

}

int rob(TreeNode *root) {
    std::unordered_map<TreeNode *, int> mf, mg;
    dfs337(root, mf, mg);
    return std::max(mg[root], mf[root]);
}
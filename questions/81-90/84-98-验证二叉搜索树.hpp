#pragma once

#include "../header/TreeNode.hpp"

#include <vector>
#include <algorithm>

void dfs98(TreeNode *root, std::vector<int> &vv) {
    if (!root)
        return;
    dfs98(root->left, vv);
    vv.emplace_back(root->val);
    dfs98(root->right, vv);

}


bool isValidBST(TreeNode *root) {
    std::vector<int> tmp;
    dfs98(root, tmp);
    auto res = [](std::vector<int> &t) {
        for (int i = 1, j = 0; i < t.size();) {
            if (t[i] >= t[j])
                return false;
        }
        return true;
    };
    return res(tmp);
}
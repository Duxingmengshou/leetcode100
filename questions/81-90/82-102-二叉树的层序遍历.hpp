#pragma once

#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <queue>
#include "../header/TreeNode.hpp"


std::vector<std::vector<int>> levelOrder(TreeNode *root) {

    std::vector<std::vector<int>> ret;
    if (!root) {
        return ret;
    }

    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(std::vector<int>());
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front();
            q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return ret;
}